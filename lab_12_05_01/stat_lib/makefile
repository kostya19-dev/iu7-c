# Директории
INCLUDE_DIR := ./inc
SOURCE_DIR := ./src
OUTPUT_DIR := ./out
TEST_DIR := ./unit_tests
FUNC_TEST_DIR := ./func_tests
ROOT_DIR = .
LIB_DIR := ./lib

# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -I $(INCLUDE_DIR) -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wpedantic
# Флаги линковки
LDFLAGS := -L$(LIB_DIR) -lm
TEST_FLAGS := -lcheck -lrt -lm -lpthread -lsubunit

# Поиск исходных файлов
SRC_FILES := $(wildcard $(SOURCE_DIR)/*.c)
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(SRC_FILES))

# Тестовые файлы и объектные файлы
TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(TEST_SRC_FILES))

# Цели
.PHONY: all app.exe debug tests clean gcov unit_tests.exe func_tests collect_coverage src lib

all: app.exe unit_tests.exe


# Сборка статической библиотеки
lib: $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $(LIB_DIR)/libmylib.a $^
	@echo "Static library 'libmylib.a' created successfully."

# Сборка основной программы с использованием статической библиотеки
app.exe: lib
	@mkdir -p $(ROOT_DIR)
	$(CC) $(CFLAGS) -o $(ROOT_DIR)/app.exe $(SOURCE_DIR)/main.c $(LDFLAGS) -lmylib
	@echo "File 'app.exe' created successfully."

# Сборка модульных тестов с использованием статической библиотеки
unit_tests.exe: lib $(TEST_OBJ_FILES)
	@mkdir -p $(ROOT_DIR)
	$(CC) $(CFLAGS) $(TEST_OBJ_FILES) $(LDFLAGS) -lmylib -o $(ROOT_DIR)/unit_tests.exe $(TEST_FLAGS)
	@echo "File 'unit_tests.exe' created successfully."

# Сборка и прогон модульных тестов
unit: unit_tests.exe
	@./$(ROOT_DIR)/unit_tests.exe

# Прогон функциональных тестов
func_tests:
	@./func_tests/scripts/run_func_tests.sh

# Компиляция исходных файлов
$(OUTPUT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция тестов
$(OUTPUT_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	@rm -rf $(OUTPUT_DIR)/*.o $(ROOT_DIR)/app.exe $(ROOT_DIR)/unit_tests.exe $(LIB_DIR)/libmylib.a
	@echo "Cleaned up successfully."
