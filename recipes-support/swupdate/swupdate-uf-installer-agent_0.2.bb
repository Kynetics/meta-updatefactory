SUMMARY = "SWUpdate Update Factory configuration files for Installer Agent"

require swupdate-uf-agent.inc

SRC_URI += "\
	file://swupdate-feeder \
	file://install_success.uenv \
	file://install_failure.uenv \
	file://update_finished.uenv \
"

RDEPENDS:${PN} += "swupdate-tools"

do_install:append() {
	install -d ${D}${bindir}/
	install -m 0755 ${WORKDIR}/swupdate-feeder ${D}${bindir}/
	install -d ${D}${sysconfdir}/swupdate/uboot
	install -m 0644 ${WORKDIR}/install_success.uenv ${D}${sysconfdir}/swupdate/uboot/
	install -m 0644 ${WORKDIR}/install_failure.uenv ${D}${sysconfdir}/swupdate/uboot/
	install -m 0644 ${WORKDIR}/update_finished.uenv ${D}${sysconfdir}/swupdate/uboot/
}

FILES:${PN} += " ${bindir}/* ${sysconfdir}/*"
