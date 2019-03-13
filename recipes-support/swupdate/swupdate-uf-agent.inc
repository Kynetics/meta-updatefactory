LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=751419260aa954499f7abaabaa882bbe"

SRC_URI = "\
	file://swupdate.cfg \
	file://swupdate-default \
	file://GPLv2.patch \
"

RDEPENDS_${PN} = "swupdate"

S = "${WORKDIR}"

inherit allarch

do_configure[noexec] = "1"
do_compile[noexec] = "1"

do_install () {
	install -d ${D}${sysconfdir}/default
	install -d ${D}${sysconfdir}/swupdate
	install -m 0644 ${WORKDIR}/swupdate.cfg ${D}${sysconfdir}/swupdate/
	install -m 0644 ${WORKDIR}/swupdate-default ${D}${sysconfdir}/default/swupdate
}

FILES_${PN} = "${sysconfdir}/*"
CONFFILES_${PN} += "${sysconfdir}/swupdate/swupdate.cfg ${sysconfdir}/default/swupdate"
