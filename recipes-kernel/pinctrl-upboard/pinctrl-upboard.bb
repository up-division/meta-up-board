SUMMARY = "UP boards pin controller modules"
DESCRIPTION = "${SUMMARY}"
LICENSE = "CLOSED"

SRCREV = "${AUTOREV}"
PV = "1.0.0-git${SRCPV}"
SRC_URI = "git://github.com/up-division/pinctrl-upboard.git;protocol=https;branch=master"

S = "${WORKDIR}/git/files"

inherit module

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.

RPROVIDES:${PN} += "kernel-module-upboard-cpld"
RPROVIDES:${PN} += "kernel-module-upboard-ec"
RPROVIDES:${PN} += "kernel-module-leds-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upelement"
RPROVIDES:${PN} += "kernel-module-pwm-upboard"
