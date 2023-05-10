SUMMARY = "Provide a basic init script to enable audio"
DESCRIPTION = "Set the volume and unmute the Front mixer setting during boot."
LICENSE = "BSD-4-Clause"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/BSD-4-Clause;md5=624d9e67e8ac41a78f6b6c2c55a83a2b"

inherit systemd 

SRC_URI = "file://amixeron.service \
           file://amixeron.sh \
          "

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} = "amixeron.service"

RDEPENDS:${PN} += "bash"

do_install() {
	install -d ${D}${sysconfdir}/systemd/system
	install -m 0755 ${WORKDIR}/amixeron.service ${D}${sysconfdir}/systemd/system
        install -d ${D}${sbindir}/
	install -m 0755 ${WORKDIR}/amixeron.sh ${D}${sbindir}/
}





