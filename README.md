# meta-up-board

Yocto Project BSP layer for UP Board (AAEON) hardware.

* Yocto Project release: wrynose (Yocto Project 6.0)
* Linux kernel: 6.18

This layer is **BSP-only**: machine configs, kernel fragments, and
hardware recipes (pinctrl, firmware, ACPI). Demo images and distro
policy live in
[meta-up-demo-distro](https://github.com/up-division/meta-up-demo-distro).

For product information, see http://up-board.org

## Dependencies

| Layer      | Branch  | Link                                              |
|------------|---------|----------------------------------------------------|
| core       | wrynose | https://git.openembedded.org/openembedded-core     |
| meta-intel | wrynose | https://git.yoctoproject.org/meta-intel             |

## Supported boards

| Product / family    | Machine configuration               |
|---------------------|-------------------------------------|
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

## Build an image

Clone this layer from the `master` branch, then follow the setup guide in
meta-up-demo-distro:

https://github.com/up-division/meta-up-demo-distro/blob/master/README.md
