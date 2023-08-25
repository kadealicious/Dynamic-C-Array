# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Build target
TARGET = $(BUILD_DIR)/output

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
