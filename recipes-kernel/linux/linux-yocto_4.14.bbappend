FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.1"

COMPATIBLE_MACHINE_up-board = "up-board"
COMPATIBLE_MACHINE_up-core = "up-core"

SRC_URI += " \
	file://up-board.cfg \
	file://up-board-user-config.cfg \
	file://0001-i2c-designware-platdrv-add-module-parameter-to-overr.patch \
	file://0002-disable-RTS-override-on-LPSS-UART-with-Auto-Flow-Con.patch \
	file://0003-iio-adc128s052-allow-driver-to-be-matched-using-ACPI.patch \
	file://0004-ACPI-Add-support-to-map-GPIO-resources-to-ranges.patch \
	file://0005-pinctrl-intel-Add-intel_gpio_get_direction.patch \
	file://0006-pinctrl-allow-multiple-pin-controllers-for-a-GPIO.patch \
	file://0007-regmap-Expose-regmap_writable-function-to-check-if-a.patch \
	file://0008-iio-adc128s052-allow-device-to-be-matched-using-acpi.patch \
	file://0009-mfd-Add-support-for-UP-board-CPLD-FPGA.patch \
	file://0010-up-pinctrl-Bring-in-legacy-fpga-and-pinctrl-driver.patch \
	file://0011-pinctrl-rework-for-core.c.patch \
	file://0012-acpi-acpi_node_add_pin_mapping-added-to-header-file.patch \
	file://0013-upboard-added-support-for-UP-core-CREX-HAT.patch \
	file://0014-upboard-Add-support-for-UP-CRST02.patch \
	file://0016-pinctrl-upboard-add-regmap-patches-for-CREX-and-CRST.patch \
	file://0017-pinctrl-upboard-add-separate-regmap-patches-for-CREX.patch \
	file://0018-correct-the-number-of-GPIOs-for-CREX-and-CRST02-boar.patch \
	file://0019-spi-pxa2xx-Set-dir-and-value-when-requesting-cs-gpio.patch \
	file://0020-platform-x86-upboard-Add-gpio-chip-select-for-UP-Boa.patch \
	file://0021-i2c-designware-platdrv-Use-ACPI-method-FREQ-to-get-i.patch \
	file://0022-PM-i2c-designware-platdrv-Clean-up-PM-handling-in-pr.patch \
	file://0023-PM-mfd-intel-lpss-Push-system-sleep-callbacks-to-lat.patch \
	file://0024-PM-i2c-designware-platdrv-Suspend-resume-at-the-late.patch \
"

# replace these SRCREVs with the real commit ids once you've had
# the appropriate changes committed to the upstream linux-yocto repo
SRCREV_machine_pn-linux-yocto_up-board ?= "${AUTOREV}"
SRCREV_meta_pn-linux-yocto_up-board ?= "${AUTOREV}"

#Remove the following line once AUTOREV is locked to a certain SRCREV
KERNEL_VERSION_SANITY_SKIP = "1"
