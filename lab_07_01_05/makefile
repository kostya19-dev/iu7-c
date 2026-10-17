# Директории
INCLUDE_DIR := ./inc
SOURCE_DIR := ./src
OUTPUT_DIR := ./out
TEST_DIR := ./unit_tests
FUNC_TEST_DIR := ./func_tests
ROOT_DIR = .

# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -I $(INCLUDE_DIR) -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wpedantic 
# Флаги линковки
LDFLAGS := -lm
TEST_FLAGS := -lcheck -lrt -lm -lpthread 

# Поиск исходных файлов
SRC_FILES := $(wildcard $(SOURCE_DIR)/*.c)
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(SRC_FILES))

# Тестовые файлы и объектные файлы
TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(TEST_SRC_FILES))

# Цели
.PHONY: all app.exe debug tests clean gcov unit_tests.exe func_tests collect_coverage src


all: app.exe unit_tests.exe

# Сборка основной программы
app.exe: $(OBJ_FILES)
	@mkdir -p $(ROOT_DIR)
	$(CC) $(CFLAGS) $^ -o $(ROOT_DIR)/app.exe $(LDFLAGS)
	@echo "File 'app.exe' created successfully."

# Сборка модульных тестов
unit_tests.exe: $(TEST_OBJ_FILES) $(filter-out $(OUTPUT_DIR)/main.o, $(OBJ_FILES))
	@mkdir -p $(ROOT_DIR)
	$(CC) $(CFLAGS) $^ -o $(ROOT_DIR)/unit_tests.exe $(TEST_FLAGS)

# Сборка и прогон модульных тестов
unit: unit_tests
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
	@rm -rf $(OUTPUT_DIR)/*.o $(ROOT_DIR)/app.exe $(ROOT_DIR)/unit_tests.exe
