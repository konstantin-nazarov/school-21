# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krakharo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 16:01:11 by krakharo          #+#    #+#              #
#    Updated: 2019/02/24 12:09:34 by krakharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCSDIR = ./src/
SRCS = $(patsubst $(SRCSDIR)%, %, $(wildcard $(SRCSDIR)*.c))
HEADDIR = ./include/
HEAD = $(patsubst $(HEADDIR)%, %, $(wildcard $(HEADDIR)*.h))
OBJSDIR = ./.obj/
OBJS = $(SRCS:.c=.o)
LIBNAME = libft.a
LIBDIR = ./libft/
CC = clang
ADDFLAGS = -I $(HEADDIR) -I $(LIBDIR) -I ./minilibx/
FLAGS = -g#-Wall -Wextra -Werror
MLXFLG = -L ./minilibx -lmlx -framework OpenGL -framework AppKit -framework OpenCL
MLXADDFLG = -L$(LIBDIR) -lft -I ./minilibx/

vpath %.c $(SRCSDIR)
vpath %.o $(OBJSDIR)

all: $(addprefix $(LIBDIR), $(LIBNAME)) $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CC) -I /usr/local/include $(addprefix $(OBJSDIR), $(OBJS)) $(MLXFLG) $(MLXADDFLG) -o $(NAME)

%.o: %.c $(addprefix $(HEADDIR), $(HEAD))
	$(CC) $(FLAGS) $(ADDFLAGS) -c $< -o $(OBJSDIR)$@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rea:
	make -C $(LIBDIR) re
	make re

fcleana: fclean
	make -C $(LIBDIR) fclean

cleana: clean
	make -C $(LIBDIR) clean

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(addprefix $(LIBDIR), $(LIBNAME)):
	make -C $(LIBDIR) all

norm:
	@norminette $(addprefix $(HEADDIR), $(HEAD)) $(addprefix $(SRCSDIR), $(SRCS))

a: all
	./a.out scn/scn12.rt
