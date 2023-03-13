SUMMARY = "Update Factory recovery OS startup script"
SECTION = "base"
LICENSE = "EPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/EPL-2.0;md5=2dd765ca47a05140be15ebafddbeadfe"

SRC_URI = "file://rcS.swupdate \
	"

RPROVIDES:${PN} += "virtual/initscripts-swupdate"

RDEPENDS:${PN} = "util-linux-mount"

S = "${WORKDIR}"

do_install () {
	install -d ${D}${base_sbindir}
	install -m 755 ${S}/rcS.swupdate ${D}${base_sbindir}/init
}

PACKAGES = "${PN}"
FILES:${PN} = "${base_sbindir}"

inherit allarch
