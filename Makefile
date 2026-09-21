# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++17

# Target and Source Files
TARGET := bin/game.out
SOURCES := src/main.cpp

# Raylib
RAYFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


# Gurobi-specific
GUROBI_HOME := /opt/gurobi1303/linux64
GUROBI_INC := $(GUROBI_HOME)/include
GUROBI_LIB := $(GUROBI_HOME)/lib
GUROBI_LIBS := -lgurobi_c++ -lgurobi130


DEFAULT_GOAL := run

run: compile
	./$(TARGET)

compile: $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(RAYFLAGS) \
	-o $(TARGET)

clean:
	rm -f $(TARGET)
