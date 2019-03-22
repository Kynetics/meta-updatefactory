SUMMARY = "Update Factory recovery OS startup script"
SECTION = "base"
LICENSE = "EPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/EPL-2.0;md5=2dd765ca47a05140be15ebafddbeadfe"

SRC_URI = "file://rcS.swupdate \
	"

RPROVIDES_${PN} += "virtual/initscripts-swupdate"

RDEPENDS_${PN} = "util-linux-mount"

S = "${WORKDIR}"

do_install () {
	install -d ${D}${base_sbindir}
	install -m 755 ${S}/rcS.swupdate ${D}${base_sbindir}/init
}

PACKAGES = "${PN}"
FILES_${PN} = "${base_sbindir}"

inherit allarch
