FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}-uf:"

SRC_URI += "\
file://sign_pub.pem \
	file://01-swupdate-args \
	file://10-validate-update \
	file://15-finalize-update \
	file://20-pubkey \
	file://30-install-to \
	file://swupdate-updates.env \
	file://0001-Log-save_state.patch \
	file://0003-Drop-unused-UPDATE_STATE_CHOICE_NONE.patch \
	file://swupdate.cfg \
"


RDEPENDS:${PN} = "libgcc"

do_install:append() {
	install -d ${D}${sysconfdir}/swupdate
	install -m 0644 ${WORKDIR}/swupdate-updates.env ${D}${sysconfdir}/swupdate/swupdate.env
	install -m 0644 ${WORKDIR}/sign_pub.pem ${D}${sysconfdir}/swupdate/sign_pub.pem

	install -d ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/01-swupdate-args ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/10-validate-update ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/15-finalize-update ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/20-pubkey ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/30-install-to ${D}${sysconfdir}/swupdate/conf.d
	install -m 0644 ${WORKDIR}/swupdate.cfg ${D}${sysconfdir}/swupdate/
}
