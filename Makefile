# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 10:46:13 by pntsunts          #+#    #+#              #
#    Updated: 2020/07/27 14:57:00 by pntsunts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Werror -Wextra

SRC = main.c get_next_line.c split.c change.c ft_setenv.c ft_unsetenv.c bin_exec.c ft_echo.c setup.c

OBJ = main.o get_next_line.o split.o change.o ft_setenv.o ft_unsetenv.o bin_exec.o ft_echo.o setup.o

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
