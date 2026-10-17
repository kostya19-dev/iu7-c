CC = gcc
CFLAGS = -fPIC -Wall
LDFLAGS = -shared
LIB_DIR = ./lib
OUT_DIR = ./out
TARGET = $(OUT_DIR)/libarray.so
TEST_SCRIPT = func_tests/scripts/func_tests.sh
PYTHON_SCRIPT = main.py

SRC = $(wildcard $(LIB_DIR)/*.c)
OBJ = $(patsubst $(LIB_DIR)/%.c, $(OUT_DIR)/%.o, $(SRC))

all: $(TARGET)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(TARGET): $(OBJ) | $(OUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OUT_DIR)/%.o: $(LIB_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	python3 $(PYTHON_SCRIPT)

clean:
	rm -rf $(OUT_DIR)

test: all
	bash $(TEST_SCRIPT)

.PHONY: all run clean
