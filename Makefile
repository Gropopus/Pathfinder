# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 23:32:56 by thsembel          #+#    #+#              #
#    Updated: 2021/02/12 00:05:22 by thsembel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=		./srcs/

HEAD_DIR	=		./includes/

SRCS		= 		${SRC_DIR}init.c\
					${SRC_DIR}display.c\
					${SRC_DIR}algo.c\
					${SRC_DIR}main.c

HEAD		=		${HEAD_DIR}libft.h\
					${HEAD_DIR}get_next_line.h\
					${HEAD_DIR}ft_printf.h\
					${HEAD_DIR}pathfinder.h

NAME		= Pathfinder

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} -I${HEAD_DIR} ./ft_printf/libftprintf.a -o ${NAME} $(OBJS)

all:		${NAME}

clean:
			@${RM} ${OBJS} ${KEYS}

fclean:		clean
			@${RM} ${NAME} ${KEYS}

re :		fclean all

.PHONY:		all	clean	fclean re

