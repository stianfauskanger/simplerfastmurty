# Simpler Fast Murty (SFM)
* It's a simpler interface to fastmurty, and the number of priors is always set to 1 (all rows and all columns).
* Build a WASM library (and a js-wrapper).

## fastmurty
https://github.com/motrom/fastmurty

## Usage
"make" will make:
* A shared library file "sfmlib.so" in out/lib/
* A WASM library and JS-wrapper in out/wasm/
* An executable file "out/example"
* An NPM package in out/npm
Emscripten ( https://emscripten.org/ ) must be setup to build sfmlib.wasm
