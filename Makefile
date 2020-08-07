# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 13:31:15 by tmendes-          #+#    #+#              #
#    Updated: 2020/08/07 08:54:56 by tmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	= 	ft_printf.c \
			ft_printf_format_00.c \
			ft_printf_format_01.c \
			ft_printf_fields.c \
			ft_printf_conversions_00.c \
			ft_printf_conversions_01.c \
			ft_printf_conversions_02.c \
			ft_printf_conversions_03.c \
			ft_printf_scientific.c \
			ft_printf_structures.c
			
BSRCS	= 	ft_printf_bonus.c \
			ft_printf_format_00_bonus.c \
			ft_printf_format_01_bonus.c \
			ft_printf_fields_bonus.c \
			ft_printf_conversions_00_bonus.c \
			ft_printf_conversions_01_bonus.c \
			ft_printf_conversions_02_bonus.c \
			ft_printf_conversions_03_bonus.c \
			ft_printf_scientific_bonus.c \
			ft_printf_structures_bonus.c
			
OBJS	=	$(SRCS:.c=.o)
BOBJS	=	$(BSRCS:.c=.o)
FLAG	=	-Wall -Werror -Wextra
RM		=	rm -f
HEAD	= 	libftprintf.h
BHEAD	= 	libftprintf_bonus.h
AR		=	ar -rcs
LDIR	=	libft/
LNAME	= 	libft/libft.a

all:		$(NAME)

$(NAME):
			$(MAKE) -C $(LDIR)
			gcc -c $(FLAG) $(SRCS) -I.$(HEAD)
			cp $(LNAME) $(NAME)
			$(AR) $(NAME) $(OBJS)

clean:
			$(MAKE) clean -C $(LDIR)
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(MAKE) fclean -C $(LDIR)
			$(RM) $(NAME)

re:			fclean all

bonus:
			$(MAKE) -C $(LDIR)
			gcc -c $(FLAG) $(BSRCS) -I.$(BHEAD)
			cp $(LNAME) $(NAME)
			$(AR) $(NAME) $(BOBJS)

.PHONY:		all clean fclean re bonus