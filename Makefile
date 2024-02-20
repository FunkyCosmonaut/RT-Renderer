CC = g++
UNIXFLAGS = -g -Wall -std=c++20
MACFLAGS = -g -Wall -lm -lpthread
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = Render

SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(UNIXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(UNIXFLAGS) -c $< -o $@

run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET) $(BIN_DIR)/image.ppm

render:
	./$(BIN_DIR)/Render >> $(BIN_DIR)/image.ppm

show:
	feh ./$(BIN_DIR)/image.ppm

debug:
	gdb $(BIN_DIR)/$(TARGET)
