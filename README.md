# AVX Performance Analysis

This is intended to check the speedup for the AVX2 extensions in the intel processor. This will also work for AVX(1), ones simply has to node that AVX2 has 256 bit registers and the first AVX had 128.

## AVX Registers Overview

AVX2 supports 256-bit operations. This means that AVX-enabled units can operate on a combination of:

* 4 x 64 bit operands
* 2 x 64 bit + 4 x 32 bit operands
* 32 x 8 bit operands
* etc...

As long as these can be packed to a 256 bit register, they will be executed using a single instruction when using the AVX2 operands.

## Performance Analysis

### TLDR;

Have the client choose the size N of each data element (1, 2, 4, and 8 bytes). Perform operations on an array of elements of size N, such that they can be packed into a 256 bit register. Client must make sure to run this code in a single-core CPU. This can be set under the BIOS options of the computer for intel processors. To see the differences in speed, the code must be compiled to use AVX  and to not use AVX.

### Preparing your computer

Make sure you are running on a single core. Running on a single core can be done by going into the BIOS options during startup. This will provide the best results by ensuring control of the experiment. Compile two versions of the code in GCC with the flags:

- `-o avx_enabled -03 -march=native`
- `-o avx_disabled -03 -march=native -mno-sse4`

These ensure optimization for your cpu, one with AVX and one without.

If you are unsure if your CPU supports AVX, feel free to look at the assembly code and try to identify `VADDPD` instructions in the `avx_enabled` program.

### Running the code

Once compiled, the code can be run with the following command: `avx_enabled <element_size> <operands>` / `avx_disabled <element_size> <operands>`, where element size is the size of each element (1, 2, 4, or 8) and operands is the amount of operands to perform addition on.

For example you add four 8 byte elements, this can be done in one instruction for AVX2 with the following commands:

* `avx_enabled 8 4`
* `avx_disabled 8 4`

Finally, compare the execution times output. Feel free to repeat with several parameters to see how the register talks.
