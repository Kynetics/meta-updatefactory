# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL_append = "\
	u-boot-fw-utils \
"

SWUPDATE_INIT = "tiny"

# Install installer agent
IMAGE_INSTALL_append = "\
        swupdate-uf-installer-agent \
"
