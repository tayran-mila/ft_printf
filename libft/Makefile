# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 15:05:27 by tmendes-          #+#    #+#              #
#    Updated: 2020/07/27 19:27:42 by tmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	= 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_split.c \
			ft_strmapi.c \
			ft_llitoa.c \
			ft_abs.c \
			ft_dabs.c \
			ft_labs.c \
			ft_ldabs.c \
			ft_llabs.c \
			ft_lli_pot_b.c \
			ft_ld_pot_b.c \
			ft_concat.c \
			ft_strround.c \
			ft_nbrdigit.c \
			ft_ftoa.c \
			ft_ull_nbrdigit.c \
			ft_ullitoa.c
			
BSRC	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS	=	$(SRCS:.c=.o)
BOBJ	=	$(BSRC:.c=.o)
FLAG	=	-Wall -Werror -Wextra
RM		=	rm -f
HEAD	= 	libft.h
AR		=	ar -rcs

all:		$(NAME)

$(NAME):
			gcc -c $(FLAG) -I.$(HEAD) $(SRCS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BOBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(NAME)
			gcc -c $(FLAG) -I.$(HEAD) $(BSRC)
			$(AR) $(NAME) $(BOBJ)
			
.PHONY:		all clean fclean re bonus