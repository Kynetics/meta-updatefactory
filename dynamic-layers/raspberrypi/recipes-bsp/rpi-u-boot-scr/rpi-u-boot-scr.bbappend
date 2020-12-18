FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PROVIDES += "u-boot-script-regular"

do_deploy_append () {
   ln -srf ${DEPLOYDIR}/boot.scr ${DEPLOYDIR}/boot-regular.scr-${MACHINE}
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
