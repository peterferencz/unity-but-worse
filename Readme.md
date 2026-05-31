# Simple game engine
---

## Features
 - Object hierarchy with component system
 - Mesh redering with materials
 - Scriptability through behaviours

## The stack
* `premake5` is the build system
* `Glad` for basic window management
* `GlfW` for OpenGL functions
* `GLM` for math
* `Stb` for image processing

## Building
THe following commands should be run from the root of the project
```sh
premake5 gmake2
make -C Build -f Makefile -j 8 all
```