f ?= 1
ifeq ($(f), 0)
	CXXFLAGS = -std=c++17 -O2
else
	CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -fsanitize=undefined -fsanitize=address
endif
