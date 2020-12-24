FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

SRC_URI += " \
       file://up-board.cfg \
       file://up-board-user-config.cfg \
       file://0001-ACPI-Add-support-to-map-GPIO-resources-to-ranges.patch \
       file://0002-disable-RTS-override-on-LPSS-UART-with-Auto-Flow-Con.patch \
       file://0003-pinctrl-allow-multiple-pin-controllers-for-a-GPIO.patch \
       file://0004-regmap-Expose-regmap_writable-function-to-check-if-a.patch \
       file://0005-mfd-Add-support-for-UP-board-CPLD-FPGA.patch \
       file://0006-up-pinctrl-Bring-in-legacy-fpga-and-pinctrl-driver.patch \
       file://0007-acpi-acpi_node_add_pin_mapping-added-to-header-file.patch \
       file://0008-platform-x86-upboard-fix-gpio-pinctrl-API-references.patch \
       file://0009-upboard-added-support-for-UP-core-CREX-HAT.patch \
       file://0010-upboard-Add-support-for-UP-CRST02.patch \
       file://0011-pinctrl-upboard-add-regmap-patches-for-CREX-and-CRST.patch \
       file://0012-pinctrl-upboard-add-separate-regmap-patches-for-CREX.patch \
       file://0013-correct-the-number-of-GPIOs-for-CREX-and-CRST02-boar.patch \
       file://0014-upboard-fpga-Enable-fpga-on-UP3-platform.patch \
       file://0015-pinctrl-upboard-Dont-initialise-UART1-RTS-as-input.patch \
       file://0016-pinctrl-core-translate-gpio-to-pin-before-set-config.patch \
       file://0017-serial-8250_dw-add-quirk-to-disable-DMA-on-Cherry-Tr.patch \
       file://0018-up-fpga-dmi-Update-DMI-match-date-string.patch \
       file://0019-pinctrl-fpga-up-Update-DMI-data-match.patch \
       file://0020-ASoC-Intel-new-Baytrail-Cherrytrail-PCM512x-machine-.patch \
       file://0021-ASoC-Intel-bytcht_pcm512x-use-modern-dai_link-style.patch \
       file://0022-pinctrl-core-translate-gpio-to-pin-before-config.patch \
       file://0023-upboard-pinctrl-drop-regmap-patches-for-UP-Xtreme.patch \
       file://0024-up-pinctrl-change-SoC-gpio-references-to-use-h-w-pin.patch \
       file://0025-spi-pxa2xx-Set-dir-and-value-when-requesting-cs-gpio.patch \
       file://0026-platform-x86-upboard-Add-gpio-chip-select-for-UP-Boa.patch \
       file://0027-up-pinctrl-fix-null-pointer-issue.patch \
       file://0028-pinctrl-core-no-need-to-check-mux-usage-on-upboard.patch \
       file://0029-upboard-fpga-support-upn-apl01-project.patch \
       file://0030-upboard-fix-NULL-pointer-after-modifying-up_spi_cs_g.patch \
       file://intel/gfx-5.4.scc \
"
# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
# SRCREV_machine_pn-linux-yocto_up-board ?= "${AUTOREV}"
# SRCREV_meta_pn-linux-yocto_up-board ?= "${AUTOREV}"

