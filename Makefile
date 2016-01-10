# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/01/10 18:48:42 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit
INCLUDESDIR =.
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g
SOURCES =	file_checker.c file_opener.c init_list.c main.c

all :		$(NAME)
$(NAME) :
	$(CC) $(CFLAGS) libft.a $(SOURCES) -o $(NAME)
norm :
			norminette $(SOURCES) fillit.h
clean :
		-rm  -f $(NAME)
fclean :	clean
re :		fclean all
