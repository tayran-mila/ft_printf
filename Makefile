# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 13:31:15 by tmendes-          #+#    #+#              #
#    Updated: 2020/07/22 14:34:54 by tmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	= 	ft_printf.c \
			ft_printf_format.c \
			ft_printf_fields.c \
			ft_printf_conversions.c \
			ft_printf_conversions_float.c \
			ft_printf_scientific.c
			
OBJS	=	$(SRCS:.c=.o)
FLAG	=	-Wall -Werror -Wextra
RM		=	rm -f
HEAD	= 	libftprintf.h
AR		=	ar -rcs
LDIR	=	libft/
LBFT	=	-lft
LPTF 	=	-lftprintf
LNAME	= 	libft/libft.a

all:		$(NAME)

$(NAME):
			$(MAKE) -C $(LDIR)
			gcc -c $(FLAG) $(SRCS) -I.$(HEAD) -L$(LDIR) $(LBFT)
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