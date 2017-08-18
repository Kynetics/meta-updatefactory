SUMMARY = "SWUpdate Update Factory configuration files for Cloud Agent"

require swupdate-uf-agent.inc

SRC_URI += "\
	file://postdownload.sh \
	file://downloaded.uenv \
"

do_install_append() {
	install -d ${D}${bindir}/
	install -m 0755 ${WORKDIR}/postdownload.sh ${D}${bindir}/
	install -d ${D}${sysconfdir}/swupdate/uboot
	install -m 0644 ${WORKDIR}/downloaded.uenv ${D}${sysconfdir}/swupdate/uboot/
}

FILES_${PN} += " ${bindir}/* ${sysconfdir}/*"
