#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Particular machine configuration for up-core boards.

# Include additional ACPI tables with the initrd
EXTRA_IMAGEDEPENDS_append = " acpi-tables"
INITRD_LIVE_prepend = "${DEPLOY_DIR_IMAGE}/acpi-tables.cpio "


# Ampak-firmware, SystemD and network tools
IMAGE_INSTALL_append += " bluez5 systemd"
IMAGE_INSTALL_append += " hostapd wireless-tools dhcp-client iw wpa-supplicant"
IMAGE_INSTALL_append += " ampak-firmware"
DISTRO_FEATURES_append = " bluez5 bluetooth wifi"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
