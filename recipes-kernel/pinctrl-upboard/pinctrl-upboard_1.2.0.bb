SUMMARY = "UP boards pin controller modules"
DESCRIPTION = "${SUMMARY}"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=12f884d2ae1ff87c09e5b7ccc2c4ca7e"

# Pin v1.2.0 (includes UPN-WCL01 DMI, SPI mode=5, upboard_pwm_register(3)).
SRCREV = "24ae99e7e0b681a18be3b2922c8586c8c0de7148"
PV = "1.2.0+git${SRCPV}"
# Equivalent to git@github.com:up-division/pinctrl-upboard.git (bitbake ssh form).
SRC_URI = "git://github.com/up-division/pinctrl-upboard.git;protocol=ssh;user=git;branch=master"

S = "${UNPACKDIR}/${BP}/files"

inherit module

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.

RPROVIDES:${PN} += "kernel-module-upboard-fpga"
RPROVIDES:${PN} += "kernel-module-upboard-ec"
RPROVIDES:${PN} += "kernel-module-leds-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upelement"
RPROVIDES:${PN} += "kernel-module-pwm-upboard"
