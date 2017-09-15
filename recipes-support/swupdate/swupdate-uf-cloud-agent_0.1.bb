SUMMARY = "SWUpdate Update Factory configuration files for Cloud Agent"

require swupdate-uf-agent.inc

SRC_URI += "\
	file://update.env \
	file://postdownload.sh \
	file://reboot_for_update.sh \
	file://downloaded.uenv \
	file://distro_bootcmd_prepend.uenv \
"

do_install_append() {
	install -d ${D}${bindir}/
	install -m 0755 ${WORKDIR}/postdownload.sh ${D}${bindir}/
	install -m 0755 ${WORKDIR}/reboot_for_update.sh ${D}${bindir}/
	install -d ${D}${sysconfdir}/swupdate/uboot
	install -m 0644 ${WORKDIR}/update.env ${D}${sysconfdir}/swupdate/
	install -m 0644 ${WORKDIR}/downloaded.uenv ${D}${sysconfdir}/swupdate/uboot/
	install -m 0644 ${WORKDIR}/distro_bootcmd_prepend.uenv ${D}${sysconfdir}/swupdate/uboot/
}

FILES_${PN} += " ${bindir}/* ${sysconfdir}/*"
