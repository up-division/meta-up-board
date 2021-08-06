
IMAGE_FEATURES += "package-management"

IMAGE_INSTALL += "kernel-modules"
IMAGE_INSTALL += "dmidecode"
IMAGE_INSTALL += "python3"
IMAGE_INSTALL += "python3-pip"
IMAGE_INSTALL += "alsa-lib alsa-utils alsa-tools"
IMAGE_INSTALL += "dropbear parted"
IMAGE_INSTALL += "i2c-tools git vim"
IMAGE_INSTALL += "file"
IMAGE_INSTALL += "dosfstools"
IMAGE_INSTALL += "picocom"

DISTRO_FEATURES_append = " bluez5 bluetooth wifi"
IMAGE_INSTALL_append += " bluez5 systemd"
IMAGE_INSTALL_append += " hostapd dhcp-client iw wpa-supplicant"
IMAGE_INSTALL_append += " minicom"
IMAGE_INSTALL_append += " f81534-mode"
IMAGE_INSTALL_append += " xserver-xorg xserver-xf86-config xserver-nodm-config"
IMAGE_INSTALL_append += " can-utils"

LICENSE_FLAGS_WHITELIST = "commercial"

# early preinit-env handler
IMAGE_INSTALL_append = " preinit-env"
APPEND_append = " init=/sbin/preinit-env"

