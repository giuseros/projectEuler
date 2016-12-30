SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))
all: target
debug: target

all: CXXFLAGS += -O3
debug: CXXFLAGS += -DDEBUG -g

clear:
	rm $(PROGS)


target: $(PROGS)
CXXFLAGS += -std=c++11

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
