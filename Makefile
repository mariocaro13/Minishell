# Project name
NAME = minishell

# COLORS
GREEN = \033[0;32m
RESET := \033[0m

# INCLUDE directory
INCLUDE_DIR = inc
#LIBFT_DIR = $(INCLUDE_DIR)/libft

# SRC DIRS
SRC_DIR = src
PARSING_DIR = $(SRC_DIR)/parsing
EXECUTION_DIR = $(SRC_DIR)/execution
UTILS_DIR = $(SRC_DIR)/utils
##LIBFT_DIR = $(SRC_DIR)/libft

# LIBRARIES
##LIBFT = $(LIBFT_DIR)/libft.a

# Rule to build the LIBFT library 
##$(LIBFT):
##	@$(MAKE) -C $(LIBFT_DIR) --silent

#Include dirs
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I$(SRC_DIR) #-I$(LIBFT_DIR)

# Source files and object files
SRC = $(SRC_DIR)/main.c		\
	$(SRC_DIR)/minishell.c	\

# Objects files
OBJECTS = $(SRC:.c=.o)

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) #-g3  -fsanitize=address

# Compile source files into object files
%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@

# Link object files
$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)$(NAME): $(NAME) has been created successfully!$(RESET)"

# Default target to build the project
all: $(NAME)

# Clean up object files
clean:
	@rm -f $(OBJECTS)
##	@$(MAKE) -C clean --silent

# Clean up all generated files
fclean: clean
	@rm -rf $(NAME)
##	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

# Rebuild the project
re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re
