# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 21:01:02 by ccolemon          #+#    #+#              #
#    Updated: 2019/03/09 17:45:32 by ccolemon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c parcer.c input.c rotate.c grid_n_color.c line.c line_dop.c remove.c

OBJ = $(SRC:.c=.o)

FDF = fdf.h

MLX = minilibx_macos

LIBFT = libft

LIB = libft.a

WWW = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@gcc $(WWW) -I $(LIBFT) -I $(MLX) -c $^

$(LIB):
		@make -C libft

$(NAME): $(LIB) $(OBJ)
	@gcc $(WWW) -I $(LIBFT) -I $(MLX) -c $(SRC)
	@gcc $(OBJ) $(WWW) -lmlx -framework OpenGL -framework AppKit libft/$(LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
