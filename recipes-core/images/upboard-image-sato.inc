
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

DISTRO_FEATURES:append = " bluez5 bluetooth wifi"
IMAGE_INSTALL:append = " bluez5 systemd"
IMAGE_INSTALL:append = " hostapd dhcpcd iw wpa-supplicant"
IMAGE_INSTALL:append = " minicom"
IMAGE_INSTALL:append = " f81534-mode"
#IMAGE_INSTALL:append = " xserver-xorg xserver-xf86-config xserver-nodm-config"
IMAGE_INSTALL:append = " can-utils"
#IMAGE_INSTALL:append = " pulseaudio-init"
IMAGE_INSTALL:append = " devmem2"
IMAGE_INSTALL:append = " rt-tests"
IMAGE_INSTALL:append = " spitools"

LICENSE_FLAGS_ACCEPTED = "commercial"

# early preinit-env handler
IMAGE_INSTALL:append = " preinit-env"
APPEND:append = " init=/sbin/preinit-env"

