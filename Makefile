# Version 0.3
# Variables internas
SHELL :=/bin/bash
CC := gcc
CFILES := $(wildcard *.c)
OFILES := ${subst .c,.o,$(CFILES)}
HFILES :=$(wildcard *.h)

# Variables de impresion
RESET := \033[0m
BOLD := \033[1m
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
MAGENTA := \033[35m
PROGRAM_NAME := $(BLUE)$(BOLD)(MAKE)=>$(RESET)

# Variables que podes cambiar
DEFAULT_OUTPUT := shelloc_holmes
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89
EXTRACFLAGS := -g
OFLAGS := 
VALGRINDFLAGS := -s --leak-check=full --show-leak-kinds=all

# Ejecutado al hacer "make", despues de revisar los .o
.PHONY: all
all: $(OFILES)
	@echo -e "$(PROGRAM_NAME)$(YELLOW) Linking compiled files...$(RESET)"
	@$(CC) $(OFLAGS) $^ -o $(DEFAULT_OUTPUT)
	@echo -e "$(PROGRAM_NAME)$(GREEN) Compilation and linking was successful, dumped in $(DEFAULT_OUTPUT).$(RESET)\n"
ifeq ($(strip $(HFILES)),)
	@wait
else
	@echo -e "$(PROGRAM_NAME)$(YELLOW) Running Betty on header files...$(RESET)"
	@betty *.h
endif
	@echo -e "$(PROGRAM_NAME)$(GREEN) Betty checks were successful.$(RESET)\n"
	@echo -e "$(PROGRAM_NAME)$(YELLOW) Running Valgrind...$(RESET)"
	@valgrind $(VALGRINDFLAGS) ./$(DEFAULT_OUTPUT)
	@echo -e "$(PROGRAM_NAME)$(GREEN) Valgrind check was successful.$(RESET)\n"
	@echo -e "$(PROGRAM_NAME)$(MAGENTA) All checks ran successfully. Executable file name is '$(DEFAULT_OUTPUT)'$(RESET)"

# Si %.o no existe o %.c es nuevo que %.o gececear con -c y cflags
%.o: %.c
	@echo -e "$(PROGRAM_NAME)$(YELLOW) Compiling $?...$(RESET)"
	@$(CC) -c $(CFLAGS) $(EXTRACFLAGS) $^ -o $@
	@betty $?

# Creo que no es ni necesario pero no quero romper todo
%.c:
	@touch $@

# Crea main.c
.PHONY: main
main:
	@echo -e "/**\n * main - asdfg\n * Return: 0\n */\nint main(void)\n{\n\treturn (0);\n}" > main.c
	@echo -e "$(PROGRAM_NAME) Successfully created main.c$(RESET)"

# Borra todos los .o
.PHONY: clean
clean:
	rm -f *.o

# Argumento no reconocido. El phony creo que no es necesario.
.PHONY: %
%:
	@echo -e "$(PROGRAM_NAME)$(RED) ERROR.$(RESET)"


