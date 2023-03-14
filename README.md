# Yocto layer for Update Factory support

## About Update Factory
**Update Factory is an artifact content and software update delivery IoT Platform**. To learn more, please visit:  
https://www.kynetics.com/update-factory

For Update Factory documentation visit:  
https://docs.updatefactory.io/

## meta-updatefactory integration
This layer provides support for the Update Factory platform to devices using a Yocto-based embedded Linux OS.
Starting from Yocto release 4.0 (branch `kirkstone`) this layer implements the [double copy strategy](https://sbabic.github.io/swupdate/overview.html#double-copy). For those looking to implement a [single copy strategy](https://sbabic.github.io/swupdate/overview.html#single-copy-running-as-standalone-image), see [meta-updatefactory-singlecopy](https://github.com/Kynetics/meta-updatefactory-singlecopy).

This layer depends on:

 - meta-swupdate  
   https://github.com/sbabic/meta-swupdate.git

To integrate Update Factory support in your image you need to:

1. include the following snippet in your image recipe:  
 ```require <relative-path-to>/recipes-images/images/swupdate-doublecopy.inc```  
 (see for example `recipes-core/images/core-image-minimal.bbappend` and `recipes-images/images/core-image-weston.bbappend` in this layer)

Currently support has been tested with boards by:

1. [Raspberry Pi](https://www.raspberrypi.org/) (RPi 4B)  
 Please add:  
 ```RPI_USE_U_BOOT = "1"```  
 in your `local.conf` to enable U-Boot support for RPi that is required by Update Factory
1. [Toradex](https://www.toradex.com/)
1. [Boundary Devices](https://boundarydevices.com/)
1. [Variscite](https://www.variscite.com/)

The layer is designed to make it as easy as possible to add support for new hardware.

## Contributing
To contribute to this layer you should open a GitHub pull request for review.

Please refer to:  
https://www.openembedded.org/wiki/Commit_Patch_Message_Guidelines  
for some useful guidelines to follow when submitting patches.

## License

All metadata is EPL-2.0 licensed (see COPYING.EPL-2.0) unless otherwise stated.
Source code included in tree for individual recipes is under the LICENSE stated in the associated recipe (.bb file) unless otherwise stated.
