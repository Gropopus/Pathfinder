# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 00:33:14 by thsembel          #+#    #+#              #
#    Updated: 2021/07/05 14:31:50 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_str_is_digit.c\
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
					ft_strjoinfree.c\
					ft_strcat.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strcmp.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strndup.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
					ft_free_tab.c\
					ft_tab_len.c\
					ft_print_tab.c\
					get_next_line.c\
					get_next_line_utils.c\
					ft_printf_utils.c\
					ft_printf_utils2.c\
					ft_printf.c\
					get_attributes.c\
					get_precision.c\
					get_width.c\
					treat_char.c\
					treat_hexa.c\
					treat_int.c\
					treat_modulo.c\
					treat_ptr.c\
					treat_string.c

SRCS_BONUS =		ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\

HEAD_DIR	= ./

HEAD		=	libft.h\
				ft_printf.h

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= $(SRCS:.c=.o)\
				$(SRCS_BONUS:.c=.o)

NAME		= libft.a

CC			= clang

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			@ar -rc libft.a ${OBJS}

bonus:
			@$(CC) $(CFLAGS) $(SRCS_BONUS) -I${HEAD} -c ${<:.c=.o}
			@ar rc $(NAME) $(OBJS_BONUS)
			@ranlib $(NAME)

clean:
			@${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
