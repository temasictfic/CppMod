# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 22:00:32 by sciftci           #+#    #+#              #
#    Updated: 2023/06/04 22:01:13 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = zombie
SRC = newZombie.cpp randomChump.cpp main.cpp Zombie.cpp
#OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)
	
fclean: clean
	
re: fclean $(NAME)

.PHONY: all clean fclean re