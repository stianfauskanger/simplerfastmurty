CXX = g++

CFLAGS  = -g -Wall -Wfatal-errors -O3 -D DENSE -D NDEBUG

CFILES = src/fastmurty/*.cpp

SLIB = mhtda.so
$(SLIB): $(CFILES)
	$(CXX) $(CFLAGS) -shared -fPIC -o $(SLIB) $(CFILES)

all: $(SLIB)

clean:
	rm -f $(SLIB)
