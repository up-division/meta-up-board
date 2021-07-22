#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include <linux/serial.h>
#include <string.h>
#include <asm-generic/ioctls.h>

#define VERSION "$Revision: 1440 $"
#define F81534_MODE_SYSFS	"/dev/%s"

static char *m_cStringArray[] = {
	(char *)-1,
	"eModeRS232",
	"eModeRS485 - DE#/RE (TX Enable with RTS Low)",
	"eModeRS485_1 - DE/RE# (TX Enable with RTS High)",
	(char *)-1,
	NULL,
};

void usage(char *argv[])
{
	int i = 0;
	fprintf(stderr, "%s: %s\n", argv[0], VERSION);
	fprintf(stderr, "%s <port> <mode>\n\n", argv[0]);
	fprintf(stderr, "\nUart Mode table:\n");

	for (i = 0; m_cStringArray[i]; ++i) {
		if (m_cStringArray[i] == (char *)-1)
			continue;
		fprintf(stderr, "%i --> %s\n", i, m_cStringArray[i]);
	}

	fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
	int fd = -1;
	int length = 0;
	int i = 0;
	int ret = 0;
	char buf[128];
	struct serial_rs485 rs485conf;

	if (argc < 3) {
		usage(argv);
		return 1;
	}

	sprintf(buf, F81534_MODE_SYSFS, argv[1]);
	printf("Target:%s\n", buf);

	fd = open(buf, O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "open error %d\n", __LINE__);
		return 2;
	}

	i = atoi(argv[2]);

	if (m_cStringArray[i] == (char *)-1) {
		usage(argv);
		return 3;
	}

	printf("port: %s\n", argv[1]);

	if (ioctl(fd, TIOCGRS485, &rs485conf) < 0) {
		printf("Error: TIOCGRS485 ioctl not supported.\n");
		return -1;
	}

	if (rs485conf.flags & SER_RS485_ENABLED) {
		if (rs485conf.flags & SER_RS485_RTS_ON_SEND)
			printf("current mode: RS485_1\n");
		else
			printf("current mode: RS485\n");
	} else
		printf("current mode: RS232\n");

	i = atoi(argv[2]);
	memset(&rs485conf, 0, sizeof(rs485conf));

	switch (i) {
	case 1:
		break;
	case 2:
		rs485conf.flags |= SER_RS485_ENABLED;
		break;
	case 3:
		rs485conf.flags |= SER_RS485_RTS_ON_SEND | SER_RS485_ENABLED;
		break;
	default:
		break;
	}

	if (ioctl(fd, TIOCSRS485, &rs485conf) < 0) {
		printf("Error: TIOCGRS485 ioctl not supported.\n");
		return -1;
	}

	printf("change to mode: %s\n", m_cStringArray[i]);

	close(fd);

	return 0;
}
