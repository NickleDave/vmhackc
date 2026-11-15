# `vmhackc`

The VMTranslator from Elements of Computing Systems, implemented in C.

A mostly literal translation from my implementation in Python:  
https://github.com/NickleDave/vmhackpy

## Usage

To "translate" Hack VM programs to assembly, run:
```
VMTranslator Add.vm
```

By default, this will create a file with the same stem and the `.asm` extension, .e.g, `Add.vm`.

The argument `<PATH>` can either be a `.vm` file or a directory containing multiple `.vm` files, that will all be compiled into a single `.asm` file.

## Set-up

The build is done with CMake.

For the initial configuration, run the following, run the following in the project root:

```
cmake -B build
```

## Build

To build (after configuration), do the following:
```
cmake --build build
```

This produces the executable `VMTranslator`
