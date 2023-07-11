#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Common machine configuration for UP family boards.

require conf/machine/intel-corei7-64.conf

MACHINE_FEATURES += "alsa"

MACHINE_EXTRA_RRECOMMENDS += "linux-firmware v86d"

EXTRA_OECONF:append_pn-matchbox-panel-2 = " --with-battery=acpi"

GLIBC_ADDONS = "nptl"

SERIAL_CONSOLES="115200;ttyS0"

IMAGE_FSTYPES += " hddimg"

MACHINE_EXTRA_RDEPENDS += "kernel-module-upboard-cpld"
MACHINE_EXTRA_RDEPENDS += "kernel-module-upboard-ec"
MACHINE_EXTRA_RDEPENDS += "kernel-module-leds-upboard"
MACHINE_EXTRA_RDEPENDS += "kernel-module-pinctrl-upboard"
MACHINE_EXTRA_RDEPENDS += "kernel-module-pinctrl-upelement"


WKS_FILE = "${@bb.utils.contains_any("EFI_PROVIDER", "systemd-boot rmc-boot", "systemd-bootdisk-initrd.wks", "grub-bootdisk-initrd.wks", d)}"
WKS_FILE_DEPENDS:append += " acpi-tables"
