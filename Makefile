CC = g++
CFLAGS = -Wall -lm
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = Render

SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET) $(BIN_DIR)/image.ppm

render:
	./$(BIN_DIR)/Render >> $(BIN_DIR)/image.ppm

show:
	feh ./$(BIN_DIR)/image.ppm
