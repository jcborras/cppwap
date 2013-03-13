CXX = g++
#CXX = clang++
CXXFLAGS = -O2 -Wall -g
LDLIBS=-lcppcms -lbooster

.PHONY: clean

all: hello
hello: hello.cpp
clean:
	rm -f hello
