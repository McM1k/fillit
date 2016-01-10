# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/01/10 14:55:19 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit
INCLUDESDIR =.
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	file_checker.c file_opener.c tetri.c main.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
$(NAME) :
	$(CC) $(CFLAGS) libft.a $(SOURCES) -o $(NAME)
norm :
			norminette $(SOURCES) fillit.h
clean :
fclean :	clean
			-rm  -f $(NAME)
re :		fclean all
