#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Common machine configuration for UP family boards.

require conf/machine/intel-corei7-64.conf

MACHINE_FEATURES += "alsa"

MACHINE_EXTRA_RRECOMMENDS += "linux-firmware v86d"

EXTRA_OECONF:append_pn-matchbox-panel-2 = " --with-battery=acpi"

GLIBC_ADDONS = "nptl"

SERIAL_CONSOLES = "115200;ttyS0"

IMAGE_FSTYPES += " hddimg"

IMAGE_INSTALL:append = " kernel-module-upboard-fpga kernel-module-upboard-ec kernel-module-leds-upboard kernel-module-pinctrl-upboard kernel-module-pinctrl-upelement kernel-module-pwm-upboard kernel-module-spi-pxa2xx-up"


WKS_FILE = "${@bb.utils.contains_any("EFI_PROVIDER", "systemd-boot rmc-boot", "systemd-bootdisk-initrd.wks", "grub-bootdisk-initrd.wks", d)}"
WKS_FILE_DEPENDS:append = " acpi-tables"
