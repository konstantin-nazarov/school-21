# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 14:56:11 by dhorker           #+#    #+#              #
#    Updated: 2019/07/28 17:15:08 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

F_GRAPH = -lmlx -framework OpenGL -framework AppKit

F_WWW = -Wall -Wextra -Werror

LIB = $(DIR_LIB)libft.a

DIR_LIB = libft/

DIR_SOURCE = sources/

SOURCE =	$(addprefix $(DIR_SOURCE), main.c	ft_vec3.c	tracing.c	objects.c \
			lighting.c	keyboard.c	mouse.c	support_1.c)

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

%.o : %.c
	gcc -I includes -I $(DIR_LIB) -c $^ -o $@

$(LIB):
	make -C $(DIR_LIB)

$(NAME): $(LIB) $(OBJECT)
	gcc $(F_GRAPH) -I minilibx_macos -I includes -I $(DIR_LIB) $(OBJECT) $(LIB) -o $(NAME)

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(DIR_SOURCE)*.o

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all
