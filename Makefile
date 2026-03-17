# Makefile for C Test Project

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = build

# Files
SOURCES = $(SRC_DIR)/test.c
OBJECTS = $(BUILD_DIR)/test.o
TARGET = $(BIN_DIR)/test

# Phony targets
.PHONY: all build clean run

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Print information
info:
	@echo "Project: C Test"
	@echo "Build directory: $(BUILD_DIR)"
	@echo "Target: $(TARGET)"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"
