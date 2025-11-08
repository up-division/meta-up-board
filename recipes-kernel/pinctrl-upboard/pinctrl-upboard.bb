SUMMARY = "UP boards pin controller modules"
DESCRIPTION = "${SUMMARY}"
LICENSE = "CLOSED"

SRCREV = "b2194d8821eb781be85c232be042004cff4daac9"
PV = "1.1.8-git${SRCPV}"
SRC_URI = "git://github.com/up-division/pinctrl-upboard.git;protocol=https;branch=master"

S = "${WORKDIR}/git/files"

inherit module

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.

RPROVIDES:${PN} += "kernel-module-upboard-fpga"
RPROVIDES:${PN} += "kernel-module-upboard-ec"
RPROVIDES:${PN} += "kernel-module-leds-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upboard"
RPROVIDES:${PN} += "kernel-module-pinctrl-upelement"
RPROVIDES:${PN} += "kernel-module-pwm-upboard"
