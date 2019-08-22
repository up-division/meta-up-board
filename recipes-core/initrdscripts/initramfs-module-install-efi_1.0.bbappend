SUMMARY = "Append included for initramfs recipe to include acpi-tables.cpio for install version image."

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

COMPATIBLE_MACHINE_up-squared = "up-squared"
COMPATIBLE_MACHINE_up-core = "up-core"
COMPATIBLE_MACHINE_up-core-plus = "up-core-plus"
