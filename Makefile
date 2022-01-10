CXX = g++
EMXX = em++

CFLAGS  = -g -Wall -Wfatal-errors -O3 -std=c++17 -D DENSE -D NDEBUG

SFMLIB_FILES = src/sfmlib/*.cpp
FASTMURTY_FILES = src/fastmurty/*.cpp
EMBIND_FILE = src/embind/embind.cpp
HTML_FILE = src/html/index.html
NPM_PKG_DIR = src/npm-package
EXAMPLE_FILE = src/example.cpp

all: sfmlib.so sfmlib.wasm npm example

outdir:
	mkdir -p out

libdir:
	mkdir -p out/lib

wasmdir:
	mkdir -p out/wasm

npmdir:
	mkdir -p out/npm

html: wasmdir
	cp $(HTML_FILE) out/wasm/index.html

sfmlib.so: libdir
	$(CXX) $(CFLAGS) -shared -fPIC -o out/lib/sfmlib.so $(SFMLIB_FILES) $(FASTMURTY_FILES)

sfmlib.wasm: wasmdir html
	 $(EMXX) $(CFLAGS) --bind -fPIC -s SINGLE_FILE=1 -s MODULARIZE=1 -s EXPORT_NAME="createSfmModule" -o out/wasm/sfmlib.js $(SFMLIB_FILES) $(FASTMURTY_FILES) $(EMBIND_FILE)

npm: npmdir sfmlib.wasm
	(cd $(NPM_PKG_DIR) && npm install)
	cp -r $(NPM_PKG_DIR)/. out/npm
	 cp out/wasm/sfmlib.js out/npm/

example: outdir
	$(CXX) $(CFLAGS) -o out/example $(SFMLIB_FILES) $(FASTMURTY_FILES) $(EXAMPLE_FILE)

clean:
	rm -fR out
