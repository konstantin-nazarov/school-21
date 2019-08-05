# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krakharo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 16:01:11 by krakharo          #+#    #+#              #
#    Updated: 2018/11/26 23:35:01 by krakharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCSDIR = ./
SRCS = $(patsubst $(SRCSDIR)%, %, $(wildcard $(SRCSDIR)*.c))
HEADDIR = ./
HEAD = $(patsubst $(SRCSDIR)%, %, $(wildcard $(HEADDIR)*.h))
OBJSDIR = ./.obj/
OBJS = $(SRCS:.c=.o)
ADDFLAGS = -I $(HEADDIR)
FLAGS = -Wall -Wextra -Werror

vpath %.c $(SRCSDIR)
vpath %.o $(OBJSDIR)

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS) $(HEAD)
	ar rc $(NAME) $(addprefix $(OBJSDIR),$(OBJS))
	ranlib $(NAME)

main: $(OBJSDIR) $(OBJS) $(HEAD)
	@gcc $(addprefix $(OBJSDIR),$(OBJS)) -o a.out

%.o: %.c
	gcc -c $< $(FLAGS) $(ADDFLAGS) -o $(OBJSDIR)$@

clean:
	rm -rf $(addprefix $(OBJSDIR), $(OBJS))
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(OBJSDIR):
	mkdir $(OBJSDIR)

norm:
	@norminette $(addprefix $(HEADDIR),$(HEAD)) $(addprefix $(SRCSDIR),$(SRCS))
