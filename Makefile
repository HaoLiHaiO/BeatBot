CC = gcc
CFLAGS = -Wall -I src -I src/utils
LDFLAGS = -lSDL2

SRC_DIR = src
UTILS_DIR = src/utils
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
UTILS_FILES = $(wildcard $(UTILS_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o) $(UTILS_FILES:$(UTILS_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/beatbot

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
