# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 13:31:15 by tmendes-          #+#    #+#              #
#    Updated: 2020/08/07 08:18:14 by tmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	= 	ft_printf_bonus.c \
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
FLAG	=	-Wall -Werror -Wextra
RM		=	rm -f
HEAD	= 	libftprintf_bonus.h
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
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LDIR)
			$(RM) $(NAME)

re:			fclean all
			
.PHONY:		all clean fclean re bonus