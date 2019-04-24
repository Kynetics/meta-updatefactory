FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-uf:"

python() {
    partitioning_mode = d.getVar("UF_PARTITIONING_MODE", True)
    if partitioning_mode == "recovery-updates" or partitioning_mode == None:
        d.setVar("UF_ENV_FILE","swupdate-recovery-updates.env")
    elif partitioning_mode == "recovery":
        d.setVar("UF_ENV_FILE","swupdate-recovery.env")
}

SRC_URI += "\
	file://${UF_ENV_FILE} \
	file://test-sign_pub.pem \
	file://0001-Log-save_state.patch \
"

do_install_append() {
  install -d ${D}${sysconfdir}/swupdate
  install -m 0644 ${WORKDIR}/${UF_ENV_FILE} ${D}${sysconfdir}/swupdate/swupdate.env
  install -m 0644 ${WORKDIR}/test-sign_pub.pem ${D}${sysconfdir}/swupdate/sign_pub.pem
  rm ${D}${systemd_system_unitdir}/swupdate-usb@.service
}

SYSTEMD_SERVICE_${PN}_remove = "swupdate-usb@.service"

python __anonymous () {
    distro_ufcloudagent_support = d.getVar('DISTRO_UFCLOUDAGENT_SUPPORT', True)
    if bb.utils.contains('DISTRO_FEATURES','systemd',True,False,d):
        if distro_ufcloudagent_support == "enabled" :
            d.setVar("SYSTEMD_AUTO_ENABLE_${PN}", "enable")
        elif distro_ufcloudagent_support == "disabled" :
            d.setVar("SYSTEMD_AUTO_ENABLE_${PN}", "disable")
    elif bb.utils.contains('DISTRO_FEATURES','sysvinit',True,False,d):
        if distro_ufcloudagent_support == "disabled" :
            d.setVar("INITSCRIPT_PARAMS", "stop 70 .")
}
