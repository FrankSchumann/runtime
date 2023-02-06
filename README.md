# runtime

# Conan package manager

## Create
Build and upload package to Conan cache.

```bash
copa $ conan create .
```

## Install
Install conan packages and create files for building.
Must be done before Build

### Release
```bash
runtime $ conan install . --output-folder=build
```

### Debug
```bash
runtime $ conan install . --output-folder=build -s build_type=Debug
```

# CMake
Change directory to build.

```bash
runtime $ cd build
```

## Release
```bash
runtime $ cmake .. --preset release
```

## Debug
```bash
runtime $ cmake .. --preset debug
```

# Build

```bash
runtime $ cmake --build . -- -j4
```

# Import Projects

## Eclipse CDT
Import the projects to Eclipse CDT based on CMake as follows:

File -> Open Projects from File System...

## Wind River Workbench
Import the projects to the Wind River Workbench based on CMake as follows:

- Create a new CMake RTP project at folder codesys
- revert changes to .gitignore
- revert changes to CMakeLists.txt

# Git
Delete all ignored/created files.

```bash
runtime $ git clean -fxd
```
