CXX := clang++
CXXINCFLAGS := -std=c++1z -I /home/maran/eclipse/boost_1_62_0 #-Werror=narrowing #-O3
CXXFLAGS := -Wall -g $(CXXINCFLAGS) -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#CXXDEFS := -DDEBUG
LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: bin bin/fibonacci

bin/fibonacci : main.cpp fibonacci.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEFS) main.cpp fibonacci.cpp -o bin/fibonacci $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/ *~
	