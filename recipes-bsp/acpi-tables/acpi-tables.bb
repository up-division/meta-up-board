SUMMARY = "Additional ACPI tables to be included with the image"
DESCRIPTION = "This will generate an initrd including ACPI tables\
 specified in ACPI_TABLES variable. The kernel looks for these\
 tables and if found, loads and parses them. This is useful if\
 you want to add new devices to buses like I2C and SPI but not limited\
 to that."

LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/BSD;md5=3775480a712fc46a69647678acb234cb"

DEPENDS = "acpica-native"

inherit deploy

# Including ACPI tables for UP2 board
# ACPI_TABLES ?= "up2_spidev1.0.asl up2_spidev1.1.asl"
# ACPI_TABLES[doc] = "List of ACPI tables to include with the initrd"

# Including ACPI tables for UPCore board
ACPI_TABLES ?= "upcore_spidev1.0.asl upcore_spidev1.1.asl"
ACPI_TABLES[doc] = "List of ACPI tables to include with the initrd"


do_compile() {
	# Always clean up the existing tables
	rm -fr ${WORKDIR}/acpi-tables/kernel
	install -d ${WORKDIR}/acpi-tables/kernel/firmware/acpi

	for table in ${ACPI_TABLES}; do
		# If relative path is given use sample tables if
		# available for the machine in question.
		d=$(dirname $table)
		if [ "$d" = "." ]; then
			table="${THISDIR}/$table"
		fi

		[ -f "$table" ] || continue

		dest_table=$(basename $table)
		bbdebug 1 "Including ACPI table: ${table}"
		iasl -p ${WORKDIR}/acpi-tables/kernel/firmware/acpi/$dest_table $table
	done
}

do_deploy() {
	cd ${WORKDIR}/acpi-tables
	find kernel | cpio -H newc -o > ${DEPLOYDIR}/acpi-tables.cpio
}
addtask deploy before do_build after do_compile
