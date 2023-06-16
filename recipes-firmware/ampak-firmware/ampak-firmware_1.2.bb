DESCRIPTION = "Firmware for Ampak AP6214a and AP6355 Wireless/Bluetooth"
LICENSE = "CLOSED"
PR = "r0"
PN = "ampak-firmware"
PV = "0.1"
S = "${WORKDIR}"

PACKAGE_ARCH = "all"

inherit allarch

FILES:${PN} += " ${base_libdir}/modprobe.d/* ${base_libdir}/firmware/ampak/brcm/* ${sysconfdir}/firmware/* ${systemd_system_unitdir}/* "

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = " file://BCM43430A1.hcd \
      file://BCM4345C0.hcd \
      file://brcmfmac43430-sdio.bin \
      file://brcmfmac43430-sdio.txt \
      file://brcmfmac43455-sdio.bin \
      file://brcmfmac43455-sdio.txt \
      file://brcmfmac-ampak.conf \
		"

do_install () {
   install -d ${D}${base_libdir}/modprobe.d
   install -m 755 ${WORKDIR}/brcmfmac-ampak.conf ${D}${base_libdir}/modprobe.d/

   install -d ${D}${base_libdir}/firmware/ampak/brcm
   install -m 755 ${WORKDIR}/brcmfmac43430-sdio.bin ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43430-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43455-sdio.bin ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43455-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/

   install -d ${D}${sysconfdir}/firmware/
   install -m 755 ${WORKDIR}/BCM43430A1.hcd ${D}${sysconfdir}/firmware/
   install -m 755 ${WORKDIR}/BCM4345C0.hcd ${D}${sysconfdir}/firmware/

    # Refer to meta-raspberrypi, file inux-firmware-rpidistro_git.bb to add compat links. Fixes errors like
    # brcmfmac mmc1:0001:1: Direct firmware load for brcm/brcmfmac43455-sdio.AAEON-UPC-PLU.txt failed with error -2
    ln -s brcmfmac43455-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/brcmfmac43455-sdio.AAEON-UPC-PLUS.txt
    ln -s brcmfmac43430-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/brcmfmac43430-sdio.AAEON-UPC-PLUS.txt
    ln -s brcmfmac43430-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/brcmfmac43430-sdio.AAEON-UP-CHCR1.txt
}

NATIVE_SYSTEMD_SUPPORT = "1"
SYSTEMD_PACKAGES = "${PN}"
