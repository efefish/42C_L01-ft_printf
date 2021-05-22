# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 04:41:06 by tfujisaw          #+#    #+#              #
#    Updated: 2021/02/17 07:20:42 by tfujisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_checker.c ft_libft_utils.c\
			output_chr_str_poi.c output_per_int.c output_unsigned.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
