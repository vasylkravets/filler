# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkravets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 11:58:28 by vkravets          #+#    #+#              #
#    Updated: 2018/02/13 11:58:30 by vkravets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vkravets.filler

SRC = main.c ft_check.c get_next_line.c check_coord.c check_field.c value_for_return.c

O = $(SRC:.c=.o)

F =  -Wall -Wextra 

all: $(NAME)

$(NAME):
	make -C libft
		gcc $(F) $(SRC) libft/libft.a -o $(NAME)
clean:
		rm -f $(O)
cleanlib:
		make clean -C ./libft/
fcleanlib:
		make fclean -C ./libft/
fclean: clean fcleanlib
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean