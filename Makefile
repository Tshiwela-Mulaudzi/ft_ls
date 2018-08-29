# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 14:25:57 by tmulaud           #+#    #+#              #
#    Updated: 2018/08/29 11:23:37 by tmulaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TAG = gcc

NAME = ft_ls.a

CFLAGS = -Wall -Wextra -Werror 

HEADER = ft_ls.h

all: $(NAME) $(OBJ)

SRC = BigR.c compare.c dothethangs.c ft_atoi.c ft_isdigit.c \
	  ft_itoa.c ft_ls.c ft_memalloc.c ft_memccpy.c \
	  ft_memcpy.c ft_memset.c ft_putchar.c ft_putnbr.c \
	  ft_putstr.c ft_strjoin.c ft_strlen.c \
	  get_details.c main.c minusL.c smallR.c \

OBJ = $(SRC:.c=.o)

$(NAME):
	$(TAG) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

clean:
	@rm -rf $(OBJ)
	@echo "Objext files deleted"

re: fclean all


