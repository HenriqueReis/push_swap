# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemaciel <hemaciel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 18:17:20 by hemaciel          #+#    #+#              #
#    Updated: 2026/01/01 18:17:29 by hemaciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR)/

SRCS = $(SRC_DIR)/push_swap.c $(SRC_DIR)/utils.c $(SRC_DIR)/stack.c \
		$(SRC_DIR)/parsing_args.c $(SRC_DIR)/parsing.c \
		$(SRC_DIR)/operations_swap_push.c $(SRC_DIR)/operations_rotate.c $(SRC_DIR)/operations_reverse_rotate.c \
		$(SRC_DIR)/sort_small.c $(SRC_DIR)/sort_radix.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📁 Created obj directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< → $@"

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "✅ Created $(NAME)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Removed object files and obj directory"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ Removed executables and libft"

re: fclean all

.PHONY: all clean fclean re
