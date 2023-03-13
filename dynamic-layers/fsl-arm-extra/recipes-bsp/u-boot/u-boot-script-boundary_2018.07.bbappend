PROVIDES += "u-boot-script-regular"

do_deploy:append () {
   ln -sf boot.scr-${MACHINE}-${PV}-${PR} boot-regular.scr-${MACHINE}
}
