#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Common machine configuration for UP family boards.

require conf/machine/intel-corei7-64.conf

MACHINE_FEATURES += "alsa"

MACHINE_EXTRA_RRECOMMENDS += "linux-firmware v86d"

EXTRA_OECONF_append_pn-matchbox-panel-2 = " --with-battery=acpi"

GLIBC_ADDONS = "nptl"

SERIAL_CONSOLES="115200;ttyS0"

IMAGE_FSTYPES += " hddimg"

WKS_FILE = "${@bb.utils.contains_any("EFI_PROVIDER", "systemd-boot rmc-boot", "systemd-bootdisk-initrd.wks", "grub-bootdisk-initrd.wks", d)}"
WKS_FILE_DEPENDS_append += " acpi-tables"
