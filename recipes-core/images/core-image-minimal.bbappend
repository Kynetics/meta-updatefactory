require ../../recipes-images/images/swupdate-regular.inc

WKS_FILE = "sdimage-bootpart-${@d.getVar("UF_PARTITIONING_MODE", True)}.wks"
