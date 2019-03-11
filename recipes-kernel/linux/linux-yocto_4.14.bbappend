FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

COMPATIBLE_MACHINE_up-board = "up-board"
COMPATIBLE_MACHINE_up-core = "up-core"

SRC_URI += "file://up-board-standard.scc \
            file://up-board-user-linux-yocto-patches.scc \
           "

# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
SRCREV_machine_pn-linux-yocto_up-board ?= "${AUTOREV}"
SRCREV_meta_pn-linux-yocto_up-board ?= "${AUTOREV}"

#Remove the following line once AUTOREV is locked to a certain SRCREV
KERNEL_VERSION_SANITY_SKIP = "1"
