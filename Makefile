outdir = ./bin

dummy_build_folder := $(shell mkdir -p $(outdir))

SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,$(outdir)/%,$(SRCS))

all: target
debug: target

all: CXXFLAGS += -O3
debug: CXXFLAGS += -DDEBUG -g

clean:
	rm $(outdir) -rf


target: $(PROGS)
CXXFLAGS += -std=c++11

./bin/%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
