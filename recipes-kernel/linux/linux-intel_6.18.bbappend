FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

PR := "${PR}.1"

SRC_URI += " \
       file://up-board.cfg \
       file://up-board-user-config.cfg \
       file://audio.cfg \
       file://ethernet.cfg \
       file://intel-dev.cfg \
       file://intel-dev.scc \
       file://usb.cfg \
       file://ipu.cfg \
       file://wireless.cfg \
       file://up-board-pinctrl.cfg \
"

# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
# SRCREV_machine_pn-linux-yocto_up-board ?= "${AUTOREV}"
# SRCREV_meta_pn-linux-yocto_up-board ?= "${AUTOREV}"

do_configure:append() {
    bbnote "Forcing Intel Xe3 Graphics enablement as MODULES for Wildcat Lake"
    echo "CONFIG_EXPERT=y" >> ${B}/.config
    echo "CONFIG_PCI=y" >> ${B}/.config
    echo "CONFIG_DRM=y" >> ${B}/.config
    
    echo "CONFIG_DRM_XE=m" >> ${B}/.config
    echo "CONFIG_DRM_XE_DISPLAY=y" >> ${B}/.config
    
    bbnote "Disabling faulty SoundWire modules to prevent modpost error"
    echo "# CONFIG_SND_SOC_INTEL_SOUNDWIRE_LINK_BASELINE is not set" >> ${B}/.config
    echo "# CONFIG_SND_SOC_SOF_INTEL_SOUNDWIRE_LINK_BASELINE is not set" >> ${B}/.config
    echo "# CONFIG_SND_SOC_SOF_INTEL_SOUNDWIRE is not set" >> ${B}/.config
    
    echo "CONFIG_PINCTRL_INTEL_PLATFORM=y" >> ${B}/.config
    
    echo "# CONFIG_PINCTRL_UPBOARD is not set" >> ${B}/.config
    echo "# CONFIG_UPBOARD_FPGA is not set" >> ${B}/.config
    echo "# CONFIG_LEDS_UPBOARD is not set" >> ${B}/.config
    echo "# CONFIG_MFD_UPBOARD_FPGA is not set" >> ${B}/.config
    
    echo "CONFIG_SCSI_UFS_CORE=y" >> ${B}/.config
    echo "CONFIG_SCSI_UFSHCD=y" >> ${B}/.config
    echo "CONFIG_SCSI_UFSHCD_PCI=y" >> ${B}/.config
}
