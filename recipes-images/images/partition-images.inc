DEPENDS += "zstd-native"

IMAGE_CMD_wic_append() {
	for i in "boot 1" "root 2" "recovery 3"
	do
		set -- $i
		PARTLABEL=$1
		PARTNUMBER=$2
		zstd -f -T0 -c ${WORKDIR}/build-wic/*.direct.p${PARTNUMBER} > ${IMGDEPLOYDIR}/${IMAGE_NAME}.${PARTLABEL}.img.zstd
		ln -sfr ${IMGDEPLOYDIR}/${IMAGE_NAME}.${PARTLABEL}.img.zstd ${IMGDEPLOYDIR}/${IMAGE_BASENAME}.${PARTLABEL}.img.zstd
	done
}
