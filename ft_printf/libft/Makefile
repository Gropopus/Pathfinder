# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 00:33:14 by thsembel          #+#    #+#              #
#    Updated: 2021/01/09 13:01:40 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
					get_next_line.c\
					get_next_line_utils.c

SRCS_BONUS =		ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\

HEAD		=	libft.h\

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= $(SRCS:.c=.o)\
				$(SRCS_BONUS:.c=.o)

NAME		= libft.a

CC			= clang

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rc libft.a ${OBJS}

bonus:
			$(CC) $(CFLAGS) $(SRCS_BONUS) -I${HEAD} -c ${<:.c=.o}
			ar rc $(NAME) $(OBJS_BONUS)
			ranlib $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
