#custom makefile.. see readme.txt for more info!
CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic --std=c++11 -g

all: test

test: test_read.exe test_algo.exe \
		most_active_cookie.exe
	./test_read.exe

	./test_algo.exe

test_read.exe: read.cpp test_read.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_algo.exe: algorithms.cpp test_algo.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@