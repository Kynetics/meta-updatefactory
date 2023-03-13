FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:rpi = " \
	file://env.cfg \
"

UBOOT_ENV_SIZE:rpi ?= "16384"
do_compile:append:rpi() {
    if [ -n "${UBOOT_CONFIG}" -o -n "${UBOOT_DELTA_CONFIG}" ]
    then
        unset i j k
        for config in ${UBOOT_MACHINE}; do
            i=$(expr $i + 1);
            for type in ${UBOOT_CONFIG}; do
                j=$(expr $j + 1);
                if [ $j -eq $i ]
                then
                    if [ -n "${UBOOT_INITIAL_ENV}" ]; then
                       ${B}/${config}/tools/mkenvimage -s ${UBOOT_ENV_SIZE} -o ${B}/${config}/u-boot-env-${MACHINE}-${type}.bin ${B}/${config}/u-boot-initial-env-${type}
                    fi
                    unset k
                fi
            done
            unset  j
        done
        unset  i
    else
        if [ -n "${UBOOT_INITIAL_ENV}" ]; then
            ${B}/tools/mkenvimage -s ${UBOOT_ENV_SIZE} -o ${B}/u-boot-env.bin ${B}/u-boot-initial-env
        fi
    fi
}

do_deploy:append:rpi() {
    if [ -n "${UBOOT_CONFIG}" ]
    then
        for config in ${UBOOT_MACHINE}; do
            i=$(expr $i + 1);
            for type in ${UBOOT_CONFIG}; do
                j=$(expr $j + 1);
                if [ $j -eq $i ]
                then
                    if [ -n "${UBOOT_INITIAL_ENV}" ]; then
                        install -D -m 644 ${B}/${config}/u-boot-env-${MACHINE}-${type}.bin ${DEPLOYDIR}/u-boot-env-${MACHINE}-${type}-${PV}-${PR}.bin
                        cd ${DEPLOYDIR}
                        ln -sf u-boot-env-${MACHINE}-${type}-${PV}-${PR}.bin u-boot-env-${MACHINE}-${type}.bin
                        ln -sf u-boot-env-${MACHINE}-${type}-${PV}-${PR}.bin u-boot-env-${type}.bin
                    fi
                fi
            done
            unset  j
        done
        unset  i
    else
        if [ -n "${UBOOT_INITIAL_ENV}" ]; then
            install -D -m 644 ${B}/u-boot-env.bin ${DEPLOYDIR}/u-boot-env-${MACHINE}-${PV}-${PR}.bin
            cd ${DEPLOYDIR}
            ln -sf u-boot-env-${MACHINE}-${PV}-${PR}.bin u-boot-env-${MACHINE}.bin
            ln -sf u-boot-env-${MACHINE}-${PV}-${PR}.bin u-boot-env.bin
        fi
    fi
}
