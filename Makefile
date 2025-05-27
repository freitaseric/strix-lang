TARGET = bin/strix

CC = clang
CFLAGS = -g -Wall -Isrc
LDFLAGS =

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LDFLAGS += -ledit
else ifeq ($(UNAME_S),Darwin)
    LDFLAGS += -ledit
endif

SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)

HEADERS = $(wildcard $(SRC_DIR)/*.h)

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking to $(TARGET)..."
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "$(TARGET) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< -> $@..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning generated files..."
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	@echo "Clean successfully complete!"

.PHONY: all clean

list-files:
	@echo "Source files (.c): $(SOURCES)"
	@echo "Header files (.h): $(HEADERS)"
	@echo "Object files (.o): $(OBJECTS)"
