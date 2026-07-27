#@TYPE: Machine
#@NAME: up-common

#@DESCRIPTION: Common machine configuration for UP family boards.

require conf/machine/intel-corei7-64.conf

MACHINE_FEATURES += "alsa"

# Only pull the firmware every UP board actually uses, not the full
# linux-firmware umbrella package (which RRECOMMENDS every vendor's
# firmware split - Qualcomm, Nvidia, AMD, Mellanox, Mediatek, etc. -
# ballooning image size with hardware no UP board has).
# linux-firmware-i915 covers the onboard GPU (CONFIG_DRM_I915=y on every
# machine here). Camera (linux-firmware-intel-ipu6-isys) is only added on
# the specific machine confs whose boards actually have a MIPI-CSI
# connector. Onboard wifi/BT firmware is provided separately by
# ampak-firmware.
MACHINE_EXTRA_RRECOMMENDS += "linux-firmware-i915 v86d"
# meta-intel.inc unconditionally appends the bare "linux-firmware" umbrella
# package (which recommends every vendor's firmware split - Qualcomm,
# Nvidia, AMD, Mellanox, Mediatek, etc.) via MACHINE_EXTRA_RRECOMMENDS:append.
# :append is deferred and always applies after the += above, so it has to
# be explicitly removed here rather than just not added.
MACHINE_EXTRA_RRECOMMENDS:remove = "linux-firmware"

EXTRA_OECONF:append:pn-matchbox-panel-2 = " --with-battery=acpi"

GLIBC_ADDONS = "nptl"

SERIAL_CONSOLES = "115200;ttyS0"

IMAGE_FSTYPES += " hddimg"

IMAGE_INSTALL:append = " kernel-module-upboard-fpga kernel-module-upboard-ec kernel-module-leds-upboard kernel-module-pinctrl-upboard kernel-module-pinctrl-upelement kernel-module-pwm-upboard kernel-module-spi-pxa2xx-up"


WKS_FILE = "${@bb.utils.contains_any("EFI_PROVIDER", "systemd-boot rmc-boot", "systemd-bootdisk-initrd.wks", "grub-bootdisk-initrd.wks", d)}"
WKS_FILE_DEPENDS:append = " acpi-tables"
