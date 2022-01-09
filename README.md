# Simpler Fast Murty (SFM)
* It's a simpler interface to fastmurty, and the number of priors is always set to 1 (all rows and all columns).
* Build a WASM library (and a js-wrapper).

## fastmurty
https://github.com/motrom/fastmurty

## Usage
"make" will make a shared library file "sfmlib.so" in out/lib/, a wasm module and js-wrapper in out/wasm/, and an executable "out/example" file.
Emscripten ( https://emscripten.org/ ) must be setup to build sfmlib.wasm
