SUMMARY = "U-boot update factory boot scripts for Raspberry Pi"
LICENSE = "CLOSED"
DEPENDS = "u-boot-mkimage-native"

SRC_URI = " \
        file://bootscript-update.txt \
"

S = "${WORKDIR}"

PROVIDES += "u-boot-script-update"

inherit deploy

BOOTSCRIPT ??= "${S}/bootscript-update.txt"

do_mkimage () {
    # allow deploy to use the ${MACHINE} name to simplify things
    if [ ! -d ${S}/${MACHINE} ]; then
        mkdir ${S}/${MACHINE}
    fi

   sed -e 's/@@KERNEL_IMAGETYPE@@/${KERNEL_IMAGETYPE}/' \
       -e 's/@@KERNEL_BOOTCMD@@/${KERNEL_BOOTCMD}/' \
       "${BOOTSCRIPT}" > "${S}/bootscript-update-final.txt"

    uboot-mkimage -A arm -O linux -T script -C none -a 0 -e 0 \
                  -n "boot script for update" -d ${S}/bootscript-update-final.txt \
                  ${S}/${MACHINE}/boot-update.scr
}

addtask mkimage after do_compile before do_install

do_install () {
    install -D -m 644 ${S}/${MACHINE}/boot-update.scr ${D}/boot-update.scr
}

do_deploy () {
    install -D -m 644 ${D}/boot-update.scr ${DEPLOYDIR}/boot-update.scr-${MACHINE}-${PV}-${PR}

    cd ${DEPLOYDIR}
    rm -f boot-update.scr-${MACHINE}
    ln -sf boot-update.scr-${MACHINE}-${PV}-${PR} boot-update.scr-${MACHINE}
}

addtask deploy after do_install before do_build

COMPATIBLE_MACHINE = "^rpi$"

FILES:${PN} += "/"

PACKAGE_ARCH = "${MACHINE_ARCH}"

#INHIBIT_DEFAULT_DEPS = "1"
