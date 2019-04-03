#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Common machine configuration for UP family boards.

require conf/machine/intel-corei7-64.conf

MACHINE_FEATURES += "alsa"

# Include additional ACPI tables with the initrd
#EXTRA_IMAGEDEPENDS_append = " acpi-tables"
#INITRD_LIVE_prepend = "${DEPLOY_DIR_IMAGE}/acpi-tables.cpio "
#ACPI_TABLES ?= "spidev1.0.asl spidev1.1.asl"

MACHINE_EXTRA_RRECOMMENDS += "linux-firmware v86d eee-acpi-scripts"

EXTRA_OECONF_append_pn-matchbox-panel-2 = " --with-battery=acpi"

GLIBC_ADDONS = "nptl"

SERIAL_CONSOLES="115200;ttyS0"
