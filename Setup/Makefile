CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -g3 -fsanitize=address,undefined

SRCS := $(wildcard *.cpp)

%: %.cpp $(filter-out $<,$(SRCS))
        $(CXX) $(CXXFLAGS) $(SRCS) -o $@
