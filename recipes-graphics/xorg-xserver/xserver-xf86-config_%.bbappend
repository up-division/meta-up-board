FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI = " \
    file://xorg.conf.d/20-intel.conf \
"
do_install () {
        install -d ${D}/${sysconfdir}/X11/xorg.conf.d/
        install -m 0644 ${WORKDIR}/xorg.conf.d/20-intel.conf ${D}/${sysconfdir}/X11/xorg.conf.d/
}


