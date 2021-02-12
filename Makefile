# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 02:25:49 by oidrissi          #+#    #+#              #
#    Updated: 2021/02/10 17:54:14 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)


$(NAME) : 
		$(CC) $(CFLAGS) -c $(SRCS) -I ./
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)
clean:
		rm -f $(OBJECTS)

fclean: 
		rm -f $(OBJECTS)
		rm -f $(NAME)

re: fclean all

bonus: