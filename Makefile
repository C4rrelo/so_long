# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 10:58:06 by tmiguel-          #+#    #+#              #
#    Updated: 2023/04/05 14:39:23 by tmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= so_long

CFLAGS  	= -Wall -Werror -Wextra -O3 -g
INCLUDE 	= -I include

LIBFTDIR	= ./libft
LIBFT   	= $(LIBFTDIR)/libft.a

LIBMLXDIR 	= ./minilibx-linux
LIBMLX  	= $(LIBMLXDIR)/libmlx_Linux.a

PRINTFDIR	= ./ft_printf
PRINTF	= $(PRINTFDIR)/libftprintf.a

LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft
UNAME   	:= $(shell uname)
ifeq ($(UNAME), Darwin)
			CC = gcc
			LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
			CC = clang
else
			CC = gcc
			FLAGS += -D LINUX
			LFLAGS += -lbsd -lXext -lX11 -lm
endif

SRC_DIR 	= mainfiles
SRC     	= $(wildcard $(SRC_DIR)/*.c)
OBJ     	= $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C $(PRINTFDIR)
			make -C $(LIBFTDIR)
			make -C $(LIBMLXDIR)
			$(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(PRINTF) $(LIBMLX) $(LFLAGS) -o $(NAME)

clean :
			@make clean -s -C $(LIBFTDIR)
			@make clean -s -C $(LIBFTDIR)
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(LIBFT)
			rm -rf $(PRINTF)
			rm -rf $(NAME)

re:		fclean all