FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-uf:"

SRC_URI += "\
	file://0001-Log-save_state.patch \
	file://0002-Implement-prototype-file-download-for-hawkbit.patch \
	file://0003-server_hawkbit-add-artifactsstorage-parameter.patch \
	file://0004-server_hawkbit-implement-saving-to-directory.patch \
	file://0001-channel_hawkbit-log-403-HTTP-errors.patch \
	file://swupdate.env \
"

do_install_append() {
  install -d ${D}${sysconfdir}/swupdate
  install -m 0644 ${WORKDIR}/swupdate.env ${D}${sysconfdir}/swupdate/
}
