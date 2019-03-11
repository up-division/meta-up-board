FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

COMPATIBLE_MACHINE_up-squared = "up-squared"
COMPATIBLE_MACHINE_up-core-plus = "up-core-plus"

SRC_URI += "file://up-board-standard.scc \
            file://up-board-user-linux-intel-patches.scc \
           "

# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
SRCREV_machine_pn-linux-yocto_up-board ?= "${AUTOREV}"
SRCREV_meta_pn-linux-yocto_up-board ?= "${AUTOREV}"
