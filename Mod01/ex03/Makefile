# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 03:42:33 by sciftci           #+#    #+#              #
#    Updated: 2023/06/05 03:43:10 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = attack
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
#OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)
	
fclean: clean
	
re: fclean $(NAME)

.PHONY: all clean fclean re