# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 21:46:59 by thsembel          #+#    #+#              #
#    Updated: 2022/01/06 18:58:00 by thsembel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/main.cpp \
				./srcs/parsing.cpp \
				./srcs/algo.cpp \
				./srcs/display.cpp

INCLUDES	=	./libft/libft.h \
				./includes/pathfinder.hpp \
				./mlx_lib/mlx.h


HEAD		= ./includes/


LIBFT		= ./libft/libft.a

#MLX		= ./mlx_lib/libmlx_Linux.a

MLX			= ./mlx_lib/libmlx.a

MLX_DIR		= ./mlx_lib/

LIB_DIR		= ./libft/

NAME		= Pathfinder

CC			= clang++

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

LFLAGS		= -framework OpenGL -framework AppKit

#LFLAGS		= -lm -lX11 -lXext -lbsd

.c.o:
		@${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.cpp=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"


all:		${NAME}

${NAME}:	${OBJS}
			@make -C $(MLX_DIR)
			@make -C ${LIB_DIR}
			@make -C ${LIB_DIR} bonus
			@echo "${GREEN}\nlibmlx.a		has been created${NC}"
			@echo "${GREEN}\nlibft.a			has been created"
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT} ${MLX}
			@echo "pathfinder		has been created\n${NC}"


clean:
			@make -C $(LIB_DIR) clean
			@make -C ${MLX_DIR} clean
			@${RM} ${OBJS}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME}
			@echo "${GREEN}[ OK ]${RED}	so_long 	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re

