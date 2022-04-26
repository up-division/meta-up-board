FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append_x86-64 = \
" file://0001-ADC-Add-the-workaround-to-read-all-ADC-values.patch \
  file://0001-WMI-Add-support-for-IO-functions-of-AAEON-devices.patch \
"

