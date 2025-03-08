# Project name
NAME = minishell

# COLORS
GREEN = \033[0;32m
RESET := \033[0m

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) #-g3  -fsanitize=address

# INCLUDE directory
INCLUDE_DIR = inc
READLINE_DIR = /usr

# SRC DIRS
SRC_DIR = src
PROMPT_DIR = $(SRC_DIR)/prompt
PARSING_DIR = $(SRC_DIR)/parsing
EXECUTION_DIR = $(SRC_DIR)/execution
UTILS_DIR = $(SRC_DIR)/utils

# LIBRARIES
READLINE_LIB = -lreadline -lhistory -L$(READLINE_DIR)/lib
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rule to build the LIBFT library 
$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR) --silent

#Include dirs
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -L $(READLINE_DIR)/include

# Source files
SRC = $(SRC_DIR)/main.c		\
	$(SRC_DIR)/minishell.c	\
	$(PROMPT_DIR)/prompt.c	\
	$(PROMPT_DIR)/history.c	\

# Objects files
OBJECTS = $(SRC:.c=.o)

# Compile source files into object files
%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@

# Link object files
$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(READLINE_LIB)
	@echo "$(GREEN)$(NAME): $(NAME) has been created successfully!$(RESET)"

# Default target to build the project
all: $(NAME)

# Clean up object files
clean:
	@rm -f $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

# Clean up all generated files
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

# Rebuild the project
re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re
