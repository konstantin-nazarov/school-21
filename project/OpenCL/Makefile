# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:39:11 by dhorker           #+#    #+#              #
#    Updated: 2019/06/29 16:01:26 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcl.a

WWW = -Wall -Wextra -Werror

SOURCE =	device_information.c	device_max_compute_units.c	device_max_work_group_size.c \
			device_name.c			device_profile.c			device_type.c \
			device_vendor.c \
			platform_information.c	platform_extensions.c		platform_name.c \
			platform_profile.c		platform_vendor.c			platform_version.c

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(WW) -c $^

$(NAME): $(OBJECT) main.o
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
	gcc $(WW) -framework OpenCL libcl.a main.c

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
