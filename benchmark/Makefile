CXX=c++
CXXFLAGS=-std=c++11 -Wall -Wextra -Werror -pedantic

BENCHMARK_HOME=/opt/benchmark/1.3.0

INCLUDE=-I${BENCHMARK_HOME}/include -I../include
LDFLAGS=-lpthread -L${BENCHMARK_HOME}/lib -lbenchmark -L../lib -loudon
RUNPATH=../lib

BINARIES = $(patsubst %.cpp, %, $(wildcard *.cpp))

all : ${BINARIES}

% : %.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $< $(LDFLAGS) -Wl,-rpath=$(RUNPATH)

destroy : 
	rm -f $(BINARIES)
