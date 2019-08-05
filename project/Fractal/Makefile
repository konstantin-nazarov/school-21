# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 14:20:08 by dhorker           #+#    #+#              #
#    Updated: 2019/07/01 19:05:22 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

WW = -Wall -Wextra -Werror

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

LIB = libft.a

MLX = minilibx_macos/libmlx.a

FRACTAL = fractals

SUPPORT = support

OBJECT =	$(FRACTAL)/mandelbrot.o	$(FRACTAL)/julia.o \
			$(FRACTAL)/carpet.o		$(FRACTAL)/newton.o \
			$(FRACTAL)/ship.o \
			$(SUPPORT)/support_1.o	$(SUPPORT)/support_2.o \
			$(SUPPORT)/mouse.o	$(SUPPORT)/keyboard.o \
			$(SUPPORT)/mini_window.o \
			main.o opencl.o

all: $(NAME)

%.o : %.c
	@gcc $(WWW) -I . -c $^ -o $@

$(NAME): $(OBJECT)
	@gcc $(OBJECT) $(WWW) -framework OpenCL $(MLXFLAG) $(LIB) $(MLX) -I . -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf $(FRACTAL)/*.o
	@rm -rf $(SUPPORT)/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
