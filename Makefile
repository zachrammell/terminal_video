.RECIPEPREFIX=>

OUTPUT=./build/

EXE=$(OUTPUT)tv
CXX=g++
CXXFLAGS=-g -Werror -Wall -Wextra -pedantic -std=c++17
CC=gcc

LIBWINCURSES=./lib/wincurses/

lib = $(OUTPUT)lib/libwincurses.a
src = $(wildcard ./src/*.cpp)
obj = $(src:./src/%.cpp=$(OUTPUT)objects/%.o)

LDFLAGS = -lwincurses -L$(OUTPUT)lib

$(EXE): $(obj) $(lib)
>$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(obj) : $(src)
>$(CXX) $(CXXFLAGS) -c -o $@ $^

$(OUTPUT)lib/lib%.a : $(OUTPUT)objects/%.o
>ar rcs $@ $^

$(OUTPUT)objects/wincurses.o : $(LIBWINCURSES)wincurses.c
>$(CC) -c -o $@ $^

.PHONY: clean
clean:
>rm -f $(obj) $(lib) $(EXE)