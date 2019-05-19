# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:41:26 by ccolemon          #+#    #+#              #
#    Updated: 2019/02/05 20:11:19 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBNAME = libft.a

SOURCE = main.c basefill.c valid.c fillit.c output.c

OBJ = $(SOURCE:.c=.o)

HEADERS = fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c $^

$(LIBNAME):
		@make -C libft

$(NAME): $(LIBNAME) $(OBJ)
		@gcc $(FLAGS) -c $(SOURCE)
		@gcc $(FLAGS) $(OBJ) -I $(HEADERS) libft/libft.a -o $(NAME)

clean:
		@rm -f $(OBJ)
		@make clean -C libft

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all
