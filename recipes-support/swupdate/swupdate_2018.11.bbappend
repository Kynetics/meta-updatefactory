FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-uf:"

SRC_URI += "\
	file://swupdate.env \
	file://0001-Log-save_state.patch \
	file://0002-channel_hawkbit-log-403-HTTP-errors.patch \
"

do_install_append() {
  install -d ${D}${sysconfdir}/swupdate
  install -m 0644 ${WORKDIR}/swupdate.env ${D}${sysconfdir}/swupdate/
  rm ${D}${systemd_system_unitdir}/swupdate-usb@.service
}

SYSTEMD_SERVICE_${PN}_remove = "swupdate-usb@.service"

python __anonymous () {
	distro_ufcloudagent_support = d.getVar('DISTRO_UFCLOUDAGENT_SUPPORT', True)
	if distro_ufcloudagent_support == "enabled" :
		d.setVar("SYSTEMD_AUTO_ENABLE_${PN}", "enable")
	elif distro_ufcloudagent_support == "disabled" :
		d.setVar("SYSTEMD_AUTO_ENABLE_${PN}", "disable")
}
