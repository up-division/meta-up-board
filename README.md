# Yocto Project BSP for UP Board Release wrynose

This file provides a brief overview for the Yocto Project
BSP for UP Board (AAEON) hardware. For more information on the UP Board product
line, see: http://up-board.org

* Yocto Project release: wrynose (Yocto Project 6.0)
* Linux kernel: 6.18

This layer depends on:

| Layer      | Branch  | Link                                              |
|------------|---------|----------------------------------------------------|
| core       | wrynose | https://git.openembedded.org/openembedded-core     |
| meta-intel | wrynose | https://git.yoctoproject.org/meta-intel             |

## Supported Boards

The following boards are supported in this release.

| Product/Family    | Machine Configuration                |
|--------------------|--------------------------------------|
| UP Squared          | up-squared                          |
| UP 4000             | up-4000, up-4000-rt                 |
| UP 7000             | up-7000, up-7000-rt                 |
| UP Squared 6000     | up-squared-6000, up-squared-6000-rt |
| UP Squared Pro 7000 | up-squared-7000, up-squared-7000-rt |
| UP Xtreme           | up-xtreme                           |
| UP Xtreme i11       | up-xtreme-i11                       |
| UP Xtreme i12       | up-xtreme-i12, up-xtreme-i12-rt     |
| UP Xtreme i14       | up-xtreme-i14, up-xtreme-i14-rt     |
| UP Nexus WCL        | up-nexus-wcl                        |


### Build an image

For instructions on setting up a build folder and building/booting an image,
see the meta-up-demo-distro README:
https://github.com/up-division/meta-up-demo-distro/blob/wrynose/README.md
