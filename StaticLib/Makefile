CC := gcc
CFLAG := -Wall -Werror

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
BIN_FILE = main

all: create_dir $(BIN_DIR)/$(BIN_FILE)

$(BIN_DIR)/$(BIN_FILE): $(OBJ_DIR)/$(BIN_FILE).o $(OBJ_DIR)/libcalc.a
	$(CC) $< -o $@ -L$(OBJ_DIR)/ -lcalc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAG) $< -c -o $@

$(OBJ_DIR)/libcalc.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o $(OBJ_DIR)/sub.o 
	ar rc $@ $^

create_dir:
	mkdir -p bin/
	mkdir -p obj/

run:
	./$(BIN_DIR)/$(BIN_FILE)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)