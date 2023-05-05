# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 12:43:48 by tmiguel-          #+#    #+#              #
#    Updated: 2023/03/29 12:43:48 by tmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c\
			ft_numbers.c \
			ft_words.c \

OBJS	=	$(FILES:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -I.

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
