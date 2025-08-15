# raymarching-engine
A small and minimal raymarching engine written in vanilla C.

## Features
- [x] Discrete object definitions and simple "textures"
- [x] Customized image information (resolution, file name, etc.)
- [ ] Basic multisample anti-aliasing
- [ ] Advanced boolean operations
- [ ] Soft shadow support
- [ ] Complex reflections
- [ ] _And more!_

## Building & Running
Generating the final image from the engine is comprised of two steps: compiling the generator executable itself,
and running it. The best way to build your own render is to compile it alongside the engine source. If you have a custom source file describing the contents of the image named `render.c`, running the following should generate the proper executable. It is reccomended to add the `-O3` flag for optimized execution.
```
$ gcc -std=c23 -Iinclude -o engine -lm src/main.c src/vector.c render.c
$ ./engine
```
Running the `engine` executable should produce a [PPM](https://en.wikipedia.org/wiki/Netpbm) bitmap file named
`raymarch.ppm`, which contains the fully renderered output from the raymarcher.

## Examples
_See the `examples` directory_
