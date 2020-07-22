# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 13:31:15 by tmendes-          #+#    #+#              #
#    Updated: 2020/07/22 09:20:44 by tmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	= 	main.c \
			ft_printf.c \
			ft_printf_format.c \
			ft_printf_fields.c \
			ft_printf_conversions.c \
			ft_printf_conversions_float.c \
			ft_printf_scientific.c
			
OBJS	=	$(SRCS:.c=.o)
FLAG	=	-Wall -Werror -Wextra
#FLAG	=	
RM		=	rm -f
HEAD	= 	libftprintf.h
AR		=	ar -rcs
LDIR	=	libft/
LBFT	=	-lft
LPTF 	=	-lftprintf

all:		$(NAME)

$(NAME):
			gcc $(FLAG) $(SRCS) -I.$(HEAD) -L$(LDIR) $(LBFT)
			#$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
			
.PHONY:		all clean fclean re bonus