.PHONY: all clean

SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))
CFLAGS = -Wall -Werror

all: $(PROGS)

%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
