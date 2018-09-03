# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 14:25:57 by tmulaud           #+#    #+#              #
#    Updated: 2018/09/03 14:21:51 by tmulaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TAG = gcc

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror 

HEADER = ft_ls.h

all: $(NAME) $(OBJ)

SRC = Bigr.c compare.c dothethangs.c ft_atoi.c ft_isdigit.c \
	  ft_itoa.c ft_ls.c ft_memalloc.c ft_memccpy.c \
	  ft_memcpy.c ft_memset.c ft_putchar.c ft_putnbr.c \
	  ft_putstr.c ft_strjoin.c ft_strlen.c \
	  get_details.c main.c minusl.c smallr.c \
	  ft_strcmp.c countblocksize.c 
OBJ = $(SRC:.c=.o)

$(NAME):
	$(TAG) -o $(NAME) $(FLAGS) $(SRC)
#	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

clean:
	@rm -rf $(OBJ)
	@echo "Objext files deleted"

re: fclean all


