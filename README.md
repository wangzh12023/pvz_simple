# pvz_simple

## Description

This is a simple pvz game for ShanghaiTech CS100 course HW8. This game is written in C++, according to the C++20 language standard, and is built using [Cmake](https://cmake.org/). 

## Quick Play
> Only windows version is available, if you are linux/macos,  please move to `Play in vscode`

```shell
cd ./pvz_simple/pack/game
PvZ.exe
```

## Play in vscode

- First you should download [vscode](https://cmake.org/) and configure the c language environment
- Download the plug-in Cmake which helps you build this project through CMake
- Compile first(using `build` key in the `CMake` plug-in) and then run(using `Launch` key in the `CMake` plug-in)

or you can operate in shell
```shell
cd ./pvz_simple/
mkdir build
cd build
cmake ..
make
./bin/PvZ.exe
```
