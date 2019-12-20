DESCRIPTION = "Firmware for Ampak AP6214a and AP6355 Wireless/Bluetooth"
LICENSE = "CLOSED"
PR = "r0"
PN = "ampak-firmware"
PV = "0.1"
S = "${WORKDIR}"

PACKAGE_ARCH = "all"

inherit allarch

FILES_${PN} += " ${base_libdir}/modprobe.d/* ${base_libdir}/firmware/ampak/brcm/* ${sysconfdir}/firmware/ampak/* ${systemd_system_unitdir}/* "

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI_append = " file://BCM43430A1.hcd \
      file://BCM4345C0.hcd \
		file://brcmfmac43430-sdio.bin \
      file://brcmfmac43430-sdio.txt \
      file://brcmfmac43455-sdio.bin \
      file://brcmfmac43455-sdio.txt \
      file://brcmfmac-ampak.conf \
      file://firmware-ampak-ap6214a.service \
      file://firmware-ampak-ap6355.service \
		"

do_install () {
   install -d ${D}${base_libdir}/modprobe.d
   install -m 755 ${WORKDIR}/brcmfmac-ampak.conf ${D}${base_libdir}/modprobe.d/

   install -d ${D}${base_libdir}/firmware/ampak/brcm
   install -m 755 ${WORKDIR}/brcmfmac43430-sdio.bin ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43430-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43455-sdio.bin ${D}${base_libdir}/firmware/ampak/brcm/
   install -m 755 ${WORKDIR}/brcmfmac43455-sdio.txt ${D}${base_libdir}/firmware/ampak/brcm/

   install -d ${D}${sysconfdir}/firmware/ampak
   install -m 755 ${WORKDIR}/BCM43430A1.hcd ${D}${sysconfdir}/firmware/ampak/
   install -m 755 ${WORKDIR}/BCM4345C0.hcd ${D}${sysconfdir}/firmware/ampak/
   
   install -d ${D}${systemd_system_unitdir}
   install -m 644 ${WORKDIR}/firmware-ampak-ap6214a.service ${D}${systemd_system_unitdir}/firmware-ampak-ap6214a.service
   install -m 644 ${WORKDIR}/firmware-ampak-ap6355.service ${D}${systemd_system_unitdir}/firmware-ampak-ap6355.service
}

NATIVE_SYSTEMD_SUPPORT = "1"
SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "firmware-ampak-ap6214a.service firmware-ampak-ap6355.service"
