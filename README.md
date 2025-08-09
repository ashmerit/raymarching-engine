# raymarching-engine
A small and minimal raymarching engine written in vanilla C.

## Features
- [x] Discrete object definitions and simple "textures"
- [x] Basic multisample anti-aliasing
- [ ] Advanced boolean operations
- [ ] Customized image information (resolution, file name, etc.)
- [ ] Soft shadow support
- [ ] Complex reflections
- [ ] _And more!_

## Building & Running
Generating the final image from the engine is comprised of two steps: compiling the generator executable itself,
and running it. (NOTE: the process of building the engine will most likely change in the future with architecture
updates and decoupling)<br>
```
$ gcc -std=c23 -o engine -O3 -lm src/main.c src/vector.c
$ ./engine
```
Running the `engine` executable should produce a [PPM](https://en.wikipedia.org/wiki/Netpbm) bitmap file named
`raymarch.ppm`, which contains the fully renderered output from the raymarcher.

## Screenshots
_Coming soon!_
