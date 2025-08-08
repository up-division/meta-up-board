
EXTRA_IMAGE_FEATURES += "package-management"

IMAGE_INSTALL += "wayland"
IMAGE_INSTALL += "wayland-protocols"
IMAGE_INSTALL += "kernel-modules kernel-dev kernel-devsrc"
IMAGE_INSTALL += "dmidecode"
IMAGE_INSTALL += "python3"
IMAGE_INSTALL += "python3-pip"
IMAGE_INSTALL += "alsa-lib alsa-utils alsa-tools alsa-plugins"
IMAGE_INSTALL += "dropbear parted"
IMAGE_INSTALL += "i2c-tools"
IMAGE_INSTALL += "file"
IMAGE_INSTALL += "dosfstools"
IMAGE_INSTALL += "bash bash-completion"

DISTRO_FEATURES:append = " wayland opengl wifi bluetooth"
IMAGE_INSTALL:append = " bluez5 hostapd dhcpcd iw wpa-supplicant"
IMAGE_INSTALL:append = " pulseaudio pulseaudio-module-bluetooth-discover pulseaudio-module-bluetooth-policy pulseaudio-module-bluez5-device pulseaudio-module-bluez5-discover"
IMAGE_INSTALL:append = " minicom"
IMAGE_INSTALL:append = " f81534-mode"
IMAGE_INSTALL:append = " can-utils"
IMAGE_INSTALL:append = " devmem2"
IMAGE_INSTALL:append = " rt-tests hwlatdetect"
IMAGE_INSTALL:append = " spitools"
IMAGE_INSTALL:append = " packagegroup-core-buildessential"
IMAGE_INSTALL:append = " amixeron"
IMAGE_INSTALL:append = " lmsensors"
IMAGE_INSTALL:append = " bmaptool"
IMAGE_INSTALL:append = " dnsmasq"

# for mipi, browser, ...
IMAGE_INSTALL:append = " gstreamer1.0 gstreamer1.0-plugins-base-dev gstreamer1.0-plugins-bad v4l-utils media-ctl libdrm-dev"
IMAGE_INSTALL:append = " wget curl nss cups nspr gnupg udev libstdc++ libc6-dev libudev lsb-release intel-vaapi-driver tbb clinfo"
IMAGE_INSTALL:append = " gflags pango xdg-utils opencl-icd-loader"

CORE_IMAGE_EXTRA_INSTALL += " wayland"

LICENSE_FLAGS_ACCEPTED = "commercial"

# early preinit-env handler
IMAGE_INSTALL:append = " preinit-env"
APPEND:append = " init=/sbin/preinit-env"

