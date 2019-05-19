# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 19:06:23 by dhorker           #+#    #+#              #
#    Updated: 2018/11/27 22:24:43 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FCOMPIL = libft.a
FFUNCTION = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
FTITLE = includes/

all: begin

begin:
		gcc -Wall -Wextra -Werror -I$(FTITLE) -c $(FFUNCTION)
			ar rc $(FCOMPIL) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
				ranlib $(FCOMPIL)

clean:
		rm -f *.o

fclean: clean
		rm -f $(FCOMPIL)

re: fclean all
