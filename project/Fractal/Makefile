# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 14:20:08 by dhorker           #+#    #+#              #
#    Updated: 2019/03/07 17:34:10 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = fdf

# SOURCE = main.c

# OBJ = $(SOURCE:.c=.o)

# HEADERS = fdf.h

# FLAGS = -Wall -Wextra -Werror

# MFLAGS = -lmlx -framework OpenGL -framework AppKit

# LIB = libft/libft.a minilibx_macos/libmlx.a

# %.o : %.c
# 	@gcc $(FLAGS) -c $^

all: $(NAME)
	gcc main.c -lmlx -framework OpenGL -framework AppKit  libft/libft.a minilibx_macos/libmlx.a

# $(LIBNAME):
# 	@make -C libft

# $(NAME): $(LIBNAME) $(OBJ)
# 	@gcc $(FLAGS) $(MFLAGS) -c $(SOURCE)
# 	@gcc $(FLAGS) $(MFLAGS) $(OBJ) -I $(HEADERS) $(LIB) -o $(NAME)

# clean:
# 		@rm -f $(OBJ)
# 		@make clean -C libft

# fclean: clean
# 		@make fclean -C libft
# 		@rm -f $(NAME)

# re: fclean all
