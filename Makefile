# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by pcrosnie          #+#    #+#              #
#    Updated: 2016/08/18 11:15:16 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

LIB = libft/libft.a

SRC = main.c ft_operations1.c ft_operations2.c ft_algo.c ft_algo2.c

SRC2 = checker.c ft_operations1.c ft_operations2.c get_next_line.c

SRCO = $(SRC:.c=.o)

SRC2O = $(SRC2:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(SRCO) $(LIB)
	gcc $(FLAGS) -c $(SRC2)
	gcc -o $(NAME2) $(SRC2O) $(LIB)

clean:
	make -C libft clean
	rm -f $(SRCO)
	rm -f $(SRC2O)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
