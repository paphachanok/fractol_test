# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoti <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:01:07 by ppoti             #+#    #+#              #
#    Updated: 2023/07/15 20:57:07 by ppoti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = build
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT = lib/libft/libft.a
MINILIB = minilibx/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/libft
	make -C ./minilibx
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MINILIB) -framework OpenGL -framework AppKit -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C ./lib/libft
	make clean -C ./minilibx
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./lib/libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
