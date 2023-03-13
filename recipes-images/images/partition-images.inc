DEPENDS += "zstd-native"

IMAGE_CMD:wic:append() {
	for i in ${UF_COMPRESSED_PARTITIONS}
	do
		set -- $i
		PARTLABEL=$1
		PARTNUMBER=$2
		zstd -f -T0 -c ${WORKDIR}/build-wic/*.direct.p${PARTNUMBER} > ${IMGDEPLOYDIR}/${IMAGE_NAME}.${PARTLABEL}.img.zstd
		ln -sfr ${IMGDEPLOYDIR}/${IMAGE_NAME}.${PARTLABEL}.img.zstd ${IMGDEPLOYDIR}/${IMAGE_BASENAME}.${PARTLABEL}.img.zstd
	done
}
