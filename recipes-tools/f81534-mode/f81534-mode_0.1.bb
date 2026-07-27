DESCRIPTION = "F81534 change mode tool"
SECTION = "Test"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"
PR = "r0"

FILES:${PN} += "${bindir}/set_gpio"
FILES:${PN} += "${bindir}/set_mode"

S = "${UNPACKDIR}"
SRC_URI = "file://set_mode.c \
           file://set_gpio.c \
          "

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} set_gpio.c -o set_gpio
    ${CC} ${CFLAGS} ${LDFLAGS} set_mode.c -o set_mode
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/set_gpio ${D}${bindir}
    install -m 0755 ${S}/set_mode ${D}${bindir}
}
