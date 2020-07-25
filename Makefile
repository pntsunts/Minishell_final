# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 10:46:13 by pntsunts          #+#    #+#              #
#    Updated: 2020/07/25 13:12:34 by pntsunts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Werror -Wextra

SRC = main.c get_next_line.c split.c

OBJ = main.o get_next_line.o split.o

$(NAME) :
		make -C ./libft/ libft.a
		@gcc -c $(SRC) $(FLAGS)
		@gcc $(FLAGS) $(OBJ)  libft/libft.a -o $(NAME)
all: $(NAME)


clean:
		make -C ./libft/ clean
		@rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -rf $(NAME)

re:  fclean all
