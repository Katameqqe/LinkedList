# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

main:
	$(CXX) $(CXXFLAGS) -c ./$(SRC_DIR)/main.cpp -o ./$(OBJ_DIR)/main.o
	$(CXX) $(CXXFLAGS) -c ./$(SRC_DIR)/LL.cpp -o ./$(OBJ_DIR)/LL.o
	$(CXX) $(CXXFLAGS) -o ./$(BIN_DIR)/app ./$(OBJ_DIR)/main.o ./$(OBJ_DIR)/LL.o 
	./$(BIN_DIR)/app