# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++17

# Target and Source Files
TARGET := bin/game.out
SOURCES := src/main.cpp

# OS Detection
UNAME_S := $(shell uname -s)

# Raylib
ifeq ($(UNAME_S), Darwin)
    RAYLIB_PREFIX := $(shell brew --prefix raylib)
    RAYFLAGS := -I$(RAYLIB_PREFIX)/include -L$(RAYLIB_PREFIX)/lib -lraylib \
		-framework IOKit \
		-framework Cocoa \
		-framework OpenGL
else ifeq ($(UNAME_S),Linux)
    RAYFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else
    $(error Unsupported OS: $(UNAME_S))
endif

DEFAULT_GOAL := run

run: compile
	./$(TARGET)

compile: $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(RAYFLAGS) \
	-o $(TARGET)

clean:
	rm -f $(TARGET)
