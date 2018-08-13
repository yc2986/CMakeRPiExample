# CMakeRPiExample
Example project using CMake, GCC 8.1.0 cross compiler for RPi3 on macOS. For more information please refer to [my article on Medium](https://medium.com/@yuzhoucheng/setup-gcc-8-1-cross-compiler-toolchain-for-raspberry-pi-3-on-macos-high-sierra-cb3fc8b6443e).

## Toolchain Requirement
- **gcc 8.1.0**
- **CMake 3.12.0**

## Build the Project
From project root directory
```bash
cd build
cmake .. && make -j
```

## Push Sample Executable to RPi3
From project root directory
```bash
rsync -rtzh build/executable/executable pi@<pi_host_name>
```