# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 19:50:13 by dhorker           #+#    #+#              #
#    Updated: 2018/11/27 22:26:58 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FCOMPIL = ft_display_file
FFILE = *.c

all: begin

begin:
	gcc -c $(FFILE)
	gcc -o $(FCOMPIL) $(FFILE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(FCOMPIL)
