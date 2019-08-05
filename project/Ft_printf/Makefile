# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 16:47:11 by dhorker           #+#    #+#              #
#    Updated: 2019/06/06 19:18:11 by dhorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

WWW = -Wall -Wextra -Werror

LIB = libft/

SUPP = support/

TYPE = type/

OBJECT =	$(LIB)ft_memset.o		$(LIB)ft_bzero.o		$(LIB)ft_memcpy.o	$(LIB)ft_memccpy.o		$(LIB)ft_memmove.o \
			$(LIB)ft_memchr.o		$(LIB)ft_memcmp.o		$(LIB)ft_strlen.o	$(LIB)ft_strdup.o		$(LIB)ft_strcpy.o \
			$(LIB)ft_strncpy.o		$(LIB)ft_strcat.o		$(LIB)ft_strncat.o	$(LIB)ft_strlcat.o		$(LIB)ft_strchr.o \
			$(LIB)ft_strrchr.o		$(LIB)ft_strstr.o		$(LIB)ft_strnstr.o	$(LIB)ft_strcmp.o		$(LIB)ft_strncmp.o \
			$(LIB)ft_atoi.o			$(LIB)ft_isalpha.o		$(LIB)ft_isdigit.o	$(LIB)ft_isalnum.o		$(LIB)ft_isascii.o \
			$(LIB)ft_isprint.o		$(LIB)ft_toupper.o		$(LIB)ft_tolower.o	$(LIB)ft_memalloc.o		$(LIB)ft_memdel.o \
			$(LIB)ft_strnew.o		$(LIB)ft_strdel.o		$(LIB)ft_strclr.o	$(LIB)ft_striter.o		$(LIB)ft_striteri.o \
			$(LIB)ft_strmap.o		$(LIB)ft_strmapi.o		$(LIB)ft_strequ.o	$(LIB)ft_strnequ.o		$(LIB)ft_strsub.o \
			$(LIB)ft_strjoin.o		$(LIB)ft_strtrim.o		$(LIB)ft_strsplit.o	$(LIB)ft_itoa.o			$(LIB)ft_putchar.o \
			$(LIB)ft_putstr.o		$(LIB)ft_putendl.o		$(LIB)ft_putnbr.o	$(LIB)ft_putchar_fd.o	$(LIB)ft_putstr_fd.o \
			$(LIB)ft_putendl_fd.o	$(LIB)ft_putnbr_fd.o	$(LIB)ft_lstnew.o	$(LIB)ft_lstdelone.o	$(LIB)ft_lstdel.o \
			$(LIB)ft_lstadd.o		$(LIB)ft_lstiter.o		$(LIB)ft_lstmap.o	$(LIB)ft_strctrim.o		$(LIB)ft_sepchar.o \
			$(LIB)ft_putbyte1.o		$(LIB)ft_putbyte2.o		$(LIB)ft_putbyte4.o	$(LIB)ft_lstdelcut.o	$(LIB)ft_delmass.o \
			$(LIB)ft_swap.o \
			\
			$(SUPP)specificator.o	$(SUPP)support_1.o	$(SUPP)support_2.o		$(SUPP)ft_atolu.o \
			$(SUPP)ft_itoa_base.o	$(SUPP)ft_output.o	$(SUPP)ft_utoa.o		$(SUPP)out_type_diu.o \
			$(SUPP)out_type_pxo.o	$(SUPP)out_type_u.o	$(SUPP)out_type_big_x.o	$(SUPP)virtual_processing.o \
			\
			$(TYPE)type_di.o	$(TYPE)type_x.o		$(TYPE)type_u.o		$(TYPE)type_x_big.o\
			$(TYPE)type_o.o		$(TYPE)type_p.o		$(TYPE)type_c.o		$(TYPE)type_s.o \
			$(TYPE)type_f_1.o	$(TYPE)type_f_2.o \
			$(TYPE)type_lf_1.o	$(TYPE)type_lf_2.o	$(TYPE)type_lf_3.o	$(TYPE)type_lf_4.o\
			$(TYPE)type_llf_1.o	$(TYPE)type_llf_2.o	$(TYPE)type_llf_3.o	$(TYPE)type_llf_4.o\
			\
			ft_printf.o

all: $(NAME)

%.o : %.c
	@gcc $(WWW) -I $(LIB) -I. -c $^ -o $@

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@rm -f $(LIB)*.o
	@rm -f $(TYPE)*.o
	@rm -f $(SUPP)*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
