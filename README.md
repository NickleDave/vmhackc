# `vmhackc`

The VMTranslator from Elements of Computing System, implemented in C.

A mostly literal translation from my implementation in Python:  
https://github.com/NickleDave/vmhackpy

## Usage

To "translate" Hack VM programs to assembly, run:
```
VMTranslator Add.vm
```

By default, this will create a file with the same base name and the `.asm` extension.

## Set-up

The build is done with CMake.

For the initial configc, run the folluration, run the following in the project root:

```
cmake -B build
```

## Build

To build (after configuration), do the following:
```
cmake --build build
```

This produces the executable `VMTranslator`
