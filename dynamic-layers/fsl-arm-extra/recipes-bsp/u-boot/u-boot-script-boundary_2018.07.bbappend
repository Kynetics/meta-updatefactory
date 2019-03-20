PROVIDES += "u-boot-script-regular"

do_deploy_append () {
   ln -sf boot.scr-${MACHINE}-${PV}-${PR} boot-regular.scr-${MACHINE}
}
