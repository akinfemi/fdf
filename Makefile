# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/05/04 16:22:58 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CC		:= gcc
CFLAGS		+= -Wall -Wextra -Werror

CFLAGS		+= -I includes/ -I libft/ -I minilibx
LDFLAGS		:= -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT		:= libft/libft.a
MINILIBX	:= minilibx/libmlx.a

FILES		:=fdf_main

SRC		:= $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ		:= $(SRC:.c=.o)


.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft	

$(MINILIBX):
	@make -C minilibx	

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCreated FDF\033[0m"

clean:
	@make -C libft clean
	@make -C minilibx clean
	@rm -rf $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
