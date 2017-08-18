SUMMARY = "SWUpdate Update Factory configuration files for Installer Agent"

require swupdate-uf-agent.inc

SRC_URI += "\
	file://swupdate-feeder \
	file://installed.uenv \
"

RDEPENDS_${PN} += "swupdate-tools"

do_install_append() {
	install -d ${D}${bindir}/
	install -m 0755 ${WORKDIR}/swupdate-feeder ${D}${bindir}/
	install -d ${D}${sysconfdir}/swupdate/uboot
	install -m 0644 ${WORKDIR}/installed.uenv ${D}${sysconfdir}/swupdate/uboot/
}

FILES_${PN} += " ${bindir}/* ${sysconfdir}/*"
