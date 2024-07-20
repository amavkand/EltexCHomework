CC := gcc
CFLAG := -Wall -Werror

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
BIN_FILE = main
PATH_LIB = $(PWD)
LD_LIBRARY = $(LD_LIBRARY_PATH)

all: create_dir $(BIN_DIR)/$(BIN_FILE)

$(BIN_DIR)/$(BIN_FILE): $(OBJ_DIR)/$(BIN_FILE).o $(OBJ_DIR)/libcalc.so
	$(CC) $< -o $@ -L$(OBJ_DIR)/ -lcalc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAG) $< -fPIC -c -o $@

$(OBJ_DIR)/libcalc.so: $(OBJ_DIR)/add.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o $(OBJ_DIR)/sub.o 
	$(CC) -shared $^ -o $@ 

create_dir:
	mkdir -p bin/
	mkdir -p obj/

run:
	LD_LIBRARY_PATH=$(PATH_LIB)/$(OBJ_DIR)/:$(LD_LIBRARY) ./$(BIN_DIR)/$(BIN_FILE)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)