.RECIPEPREFIX=>

OUTPUT=./build/
EXE=$(OUTPUT)tv
CXX=g++
CXXFLAGS=-g -Werror -Wall -Wextra -pedantic -std=c++17

src = $(wildcard ./src/*.cpp)
src += $(wildcard ./src/*.h)
obj = $(src:./src/%.cpp=./build/objects/%.o)

LDFLAGS = 

$(EXE): $(obj)
>$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(obj) : $(src)
>$(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean
clean:
>rm -f $(obj) $(EXE)