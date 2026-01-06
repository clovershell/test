SHELL := /bin/sh
CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -O2
CXXFLAGS := -Wall -Wextra -O2
SOURCES_C := $(wildcard *.c)
SOURCES_CPP := $(wildcard *.cpp)
BINS_C := $(SOURCES_C:.c=)
BINS_CPP := $(SOURCES_CPP:.cpp=)
BINS := $(BINS_C) $(BINS_CPP)
.PHONY: all clean
all: $(BINS)
%: %.c
	$(CC) $(CFLAGS) $< -o $@
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f $(BINS)
