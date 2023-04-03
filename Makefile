ARCH ?= x86
ARCH ?= arm

ifeq ($(ARCH), x86)
CXX = g++
else
CXX = aarch64-linux-gnu-g++
endif

CXXFLAGS += -g -Wall
CXXFLAGS += -std=c++11

INCLUDE = -I./

bin_file = string_test shared_ptr_test vector_test

all: $(bin_file)

string_test: string_test.cpp
	$(CXX) -o $@ $^ ${INCLUDE} ${CXXFLAGS}

shared_ptr_test: shared_ptr_test.cpp
	$(CXX) -o $@ $^ ${INCLUDE} ${CXXFLAGS}

vector_test: vector_test.cpp
	$(CXX) -o $@ $^ ${INCLUDE} ${CXXFLAGS}

clean:
	rm -rf $(bin_file)
