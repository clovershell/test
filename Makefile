SHELL := /bin/sh
CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -O2
CXXFLAGS := -Wall -Wextra -O2
SOURCES_C := $(wildcard *.c)
SOURCES_CPP := $(wildcard *.cpp)
BIN_DIR := bin
BINS_C := $(patsubst %.c,$(BIN_DIR)/%,$(SOURCES_C))
BINS_CPP := $(patsubst %.cpp,$(BIN_DIR)/%,$(SOURCES_CPP))
BINS := $(BINS_C) $(BINS_CPP)
.PHONY: all clean $(BIN_DIR)
all: $(BIN_DIR) $(BINS)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
$(BIN_DIR)/%: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@
$(BIN_DIR)/%: %.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -rf $(BIN_DIR)
