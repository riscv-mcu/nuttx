1. Download and install toolchain

  Download Embedded toolchain from https://www.nucleisys.com/download.php. We support both Windows and Linux, but suggest using the Linux system to build.

2. Prepare build environment

  Please refer to https://nuttx.apache.org/docs/latest/quickstart/install.html to setup build environment

3. Configure and build NuttX

  $ mkdir ./nuttx_prj; cd ./nuttx_prj
  $ git clone https://github.com/riscv-mcu/nuttx.git -b nuclei_trunk nuttx
  $ git clone https://github.com/riscv-mcu/nuttx-apps.git -b trunk apps
  $ cd nuttx
  $ make distclean
  $ ./tools/configure.sh nuclei-fpga-eval:nsh
  $ make V=1

4. Run the nuttx on Nuclei QEMU

  Download NUCLEI QEMU From https://www.nucleisys.com/download.php

  $ qemu-system-riscv32 -M nuclei_evalsoc,download=ilm -cpu nuclei-n300fd -kernel nuttx -serial stdio -nodefaults -nographic

5. Run the nuttx on Nuclei FPGA

  First, download NUCLEI OpenOCD, and use the NUCLEI HBird JTAG to download NuttX ELF to the Nuclei FPGA, then trigger it to run.

6. TODO

  Support RISC-V User mode
