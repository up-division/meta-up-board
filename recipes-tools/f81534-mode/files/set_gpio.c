#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h> 
#include <sys/types.h>
#include <sys/stat.h>

#define VERSION "$Revision: 1844 $"

#define F81534_GPIO_DEV		"/sys/class/tty/%s/dev"
#define F81534_GPIO_TARGET	"/sys/class/tty/%s/device/gpio"

#define GPIOLIB_PREFIX	"gpiochip"

#define GPIOLIB_EXPORT		"/sys/class/gpio/export"
#define GPIOLIB_UNEXPORT	"/sys/class/gpio/unexport"
#define GPIOLIB_DIRECTION	"/sys/class/gpio/gpio%d/direction"
#define GPIOLIB_TARGET		"/sys/class/gpio/gpio%d/value"

enum error {
	error_no_error = 0,
	error_arg_less_than_3,
	error_port_is_not_exist,
	error_argument_fail,

	error_open_sysfs_gpio_fail,
	error_change_sysfs_gpio_fail,

	error_open_gpiolib,
	error_open_gpiolib_export_fail,
	error_open_gpiolib_unexport_fail,
};

enum gpio_mode {
	gpio_failed = -1,
	gpio_sysfs_mode,
	gpio_gpiolib_mode,
};

static char *m_pcStringArray[] = {
	"0: 000 - RS422 (EVB)",
	"1: 001 - RS232 (EVB)",
	"2: 010 - RS485 (EVB)",
	"3: 011 - RS485_1 (EVB)",
	"4: 100 - RS422_Term (EVB)",
	"5: 101 - RS232_coexist (EVB)",
	"6: 110 - RS485_Term (EVB)",
	"7: 111 - Shutdown (EVB)",
	NULL,
};


void usage(char *argv[])
{
	int i = 0;
	fprintf(stderr, "%s: %s\n", argv[0], VERSION);
	fprintf(stderr, "%s <port> <mode>\n", argv[0]);
	fprintf(stderr, "e.g., %s ttyUSB0 1\n\n", argv[0]);
	fprintf(stderr, "Uart Mode table:\n");

	for (i = 0; m_pcStringArray[i]; ++i) {
		if (m_pcStringArray[i] == (char *)-1)
			continue;
		fprintf(stderr, "%i --> %s\n", i, m_pcStringArray[i]);
	}

	fprintf(stderr, "\n");
}

enum gpio_mode checkMode(char* dev)
{
	struct stat stat_data;
	char buf[128];

	sprintf(buf, F81534_GPIO_TARGET, dev);

	if (stat(buf, &stat_data))
		return gpio_failed;

	if (S_ISDIR(stat_data.st_mode))
		return gpio_gpiolib_mode;
	else
		return gpio_sysfs_mode;
}


int gpio_sysfs(int argc, char *argv[])
{
	int length = 0;
	int fd = -1;
	int data = 0;
	char buf[128];
	char data_char = 0;

	sprintf(buf, F81534_GPIO_TARGET, argv[1]);
	
	fd = open(buf, O_RDWR); 
	if (fd < 0) {
		perror("Open Failed");
		return error_open_sysfs_gpio_fail;
	}

	memset(buf, 0, sizeof(buf));
	read(fd, buf, sizeof(buf) - 1);
	printf("Current State: %s", buf);

	/* f81534 sysfs only accept with ascii number */
	data = atoi(argv[2]);
	data_char = data + '0';

	if ((data < 0) || (data >= 8)) {
		fprintf(stderr, "argument failed: %d\n", data);
		return error_argument_fail;
	}

	length = write(fd, &data_char, 1);
	if (length != 1) {
		perror("Write Failed");
		return error_change_sysfs_gpio_fail;
	}

	printf("Set to: %s\n", m_pcStringArray[data]);

	return error_no_error;	
}

int gpio_gpiolib(int argc, char *argv[])
{
	DIR *d;
	struct dirent *dir;
	int ret, data;
	int i;
	int gpio_base;
	int len;
	int fd_export, fd_unexport, fd_value;
	char out_string[4] = "out";
	char buf[128];
	char gpiolib_set[8];
	char data_char;

	data = atoi(argv[2]);

	if ((data < 0) || (data >= 8)) {
		fprintf(stderr, "argument failed: %d\n", data);
		return error_argument_fail;
	}
	sprintf(buf, F81534_GPIO_TARGET"/", argv[1]);

	d = opendir(buf);
	if (!d) {
		fprintf(stderr, "Cant open %s\n", buf);
		return error_open_gpiolib;
	}

	while ((dir = readdir(d)) != NULL) {
		if ((dir->d_type != DT_DIR) ||
			(strncmp(dir->d_name, GPIOLIB_PREFIX, sizeof(GPIOLIB_PREFIX) - 1) != 0))
			continue;

		strcpy(gpiolib_set, &dir->d_name[sizeof(GPIOLIB_PREFIX) - 1]);
		break;
	}

	closedir(d);
	gpio_base = atoi(gpiolib_set);

	do {	
		fd_export = open(GPIOLIB_EXPORT, O_WRONLY);
		if (fd_export < 0) {
			fprintf(stderr, "open gpiolib export failed\n");
			ret = error_open_gpiolib_export_fail;
		}
		
		fd_unexport = open(GPIOLIB_UNEXPORT, O_WRONLY);
		if (fd_unexport < 0) {
			fprintf(stderr, "open gpiolib unexport failed\n");
			ret = error_open_gpiolib_unexport_fail;
		}	

		for (i = 0; i < 3; ++i) {
			sprintf(buf, "%d", gpio_base + i);

			/* export gpio */
			len = write(fd_export, buf, strlen(buf));

			/* write out direct*/
			sprintf(buf, GPIOLIB_DIRECTION, gpio_base + i);
			fd_value = open(buf, O_WRONLY);
			len = write(fd_value, out_string, strlen(out_string));
			close(fd_value);

			/* open gpio pin */
			sprintf(buf, GPIOLIB_TARGET, gpio_base + i);
			fd_value = open(buf, O_WRONLY);

			data_char = !!(data & (1 << i)) + '0';
			len = write(fd_value, &data_char, sizeof(data_char));
			close(fd_value);
		}

		/* unexport all GPIO */
		for (i = 0; i < 3; ++i) {
			sprintf(buf, "%d", gpio_base + i);
			len = write(fd_unexport, buf, strlen(buf));
		}

		ret = error_no_error;
		
	}while(0);
	close(fd_export);
	close(fd_unexport);	

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	char buf[128];
	
	if (argc < 3) {
		usage(argv);
		return error_arg_less_than_3;
	}

	sprintf(buf, F81534_GPIO_DEV, argv[1]);
	if (access(buf, F_OK | R_OK)) {
		fprintf(stderr, "Cant access %s\n", argv[1]);
		return error_port_is_not_exist;
	}

	sprintf(buf, F81534_GPIO_TARGET, argv[1]);
	printf("Target:%s\n", buf);

	switch(checkMode(argv[1])) {
		case gpio_failed:
		default:

		case gpio_sysfs_mode:
			ret = gpio_sysfs(argc, argv);
			break;
		case gpio_gpiolib_mode:
			ret = gpio_gpiolib(argc, argv);
			break;
	}

	return ret;
}
