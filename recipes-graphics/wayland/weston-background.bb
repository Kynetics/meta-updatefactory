SUMMARY = "UF Weston desktop background picture"
LICENSE = "CLOSED"

include weston-background.inc

SRC_URI = "file://${WESTON_BACKGROUND}"

do_install() {
        install -d ${D}${datadir}/backgrounds
        install -m 644 ${WORKDIR}/${WESTON_BACKGROUND} ${D}${datadir}/backgrounds
}

FILES_${PN} = "${datadir}/backgrounds"
