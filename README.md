# cpp-friendly-kernel
Make the Linux kernel friendly to C++ modules

The goal of this project is to make it easier to write C++ modules. 
All C and C++ files should be able to include the kernel headers and use the native kernel API, libraries and other modules.

## Tasks:
 - Fix the kernel headers to remove conflicts with C++
 - Provide samples and instructions
 - Provide support in the build system to compile single-file cpp modules
 - Library for basic module facilities like resource tracking, logging, error handling etc.
 
## Code should be...

### Compatible:
Module code (C and C++ alike) should be able to use macros and inline from headers, link to the kernel and modules and export services to other modules.

### Minimal:
 - Absolute minimal fixes to the kernel headers should be made
 - The C++ code will not include exceptions or rtti 

### Non intrusive:
 - Header fixes should not affect the kernel - compilation of the kernel should produce exactly the same binary files
 - As with C, C++ code must respect the environment. All limitation apply (e.g. allocations, print, file access etc.)
