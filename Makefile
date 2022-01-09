CXX = g++
EMXX = em++

CFLAGS  = -g -Wall -Wfatal-errors -O3 -std=c++17 -D DENSE -D NDEBUG

SFMLIB_FILES = src/sfmlib/*.cpp
FASTMURTY_FILES = src/fastmurty/*.cpp
EMBIND_FILE = src/embind/embind.cpp
HTML_FILE = src/html/index.html
EXAMPLE_FILE = src/example.cpp

SFMLIB = sfmlib
FASTMURTY = fastmurty
HTML = html
EXAMPLE = example

all: $(SFMLIB).so $(SFMLIB).wasm $(EXAMPLE)

outdir:
	mkdir -p out

libdir:
	mkdir -p out/lib

wasmdir:
	mkdir -p out/wasm

$(HTML): wasmdir
	cp $(HTML_FILE) out/wasm/index.html

$(SFMLIB).so: libdir
	$(CXX) $(CFLAGS) -shared -fPIC -o out/lib/$(SFMLIB).so $(SFMLIB_FILES) $(FASTMURTY_FILES)

$(SFMLIB).wasm: wasmdir $(HTML)
	$(EMXX) $(CFLAGS) --bind -fPIC -s MODULARIZE=1 -s EXPORT_NAME="createSfmModule" -o out/wasm/$(SFMLIB).js $(SFMLIB_FILES) $(FASTMURTY_FILES) $(EMBIND_FILE)

$(EXAMPLE): outdir
	$(CXX) $(CFLAGS) -o out/$(EXAMPLE) $(SFMLIB_FILES) $(FASTMURTY_FILES) $(EXAMPLE_FILE)

clean:
	rm -fR out
