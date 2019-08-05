# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 15:27:59 by dhorker           #+#    #+#              #
#    Updated: 2019/07/28 17:06:41 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

PUSH = push_swap

WW = -Wall -Wextra -Werror

LIB = $(DIR_LIB)libft.a

DIR_LIB = libft/

DIR_SUPP = support/

DIR_PUSH = push/

DIR_CHECK = check/

SRC_CHECK =	$(addprefix $(DIR_CHECK), main.c	validity.c	sorting.c) \
			$(addprefix $(DIR_SUPP), check_supp.c)

SRC_PUSH =	$(addprefix $(DIR_PUSH), main.c)
			# $(addprefix $(DIR_SUPP), )

OBJ_CHECK = $(SRC_CHECK:.c=.o)

OBJ_PUSH = $(SRC_PUSH:.c=.o)

all: $(CHECK) $(PUSH)

%.o : %.c
	gcc $(WWW) -I . -I $(DIR_LIB) -c $^ -o $@

$(LIB):
	make -C libft

$(CHECK): $(LIB) $(OBJ_CHECK)
	gcc $(OBJ_CHECK) $(LIB) $(WWW) -I . -o $(CHECK)

$(PUSH): $(LIB) $(OBJ_PUSH)
	gcc $(OBJ_PUSH) $(LIB) $(WWW) -I . -o $(PUSH)

clean:
	@make clean -C libft
	@rm -rf *.o
	@rm -rf $(DIR_SUPP)*.o
	@rm -rf $(DIR_PUSH)*.o
	@rm -rf $(DIR_CHECK)*.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(CHECK)
	@rm -rf $(PUSH)

re: fclean all
