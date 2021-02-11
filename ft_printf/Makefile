# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 15:30:59 by thsembel          #+#    #+#              #
#    Updated: 2021/01/09 13:10:14 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR 	=	obj/

SRC_DIR 	=	srcs/

LIB_DIR 	=	libft/

PRINTF_H	=	-I includes/

LIBFT_H		= 	-I srcs/libft/libft.h

SRCS	 	=	ft_printf.c\
				treat_char.c\
				treat_string.c\
				treat_hexa.c\
				treat_int.c\
				treat_ptr.c\
				treat_modulo.c\
				ft_printf_utils.c\
				ft_printf_utils2.c\
				get_attributes.c\
				get_width.c\
				get_precision.c

NAME 		=	libftprintf.a

LIBFT_A 	=	libft.a

CC			=	clang -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

CFIND		=	$(SRCS:%=$(SRC_DIR)%)

OFILE		=	$(SRCS:%.c=%.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
