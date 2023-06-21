# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 02:12:33 by sciftci           #+#    #+#              #
#    Updated: 2023/06/20 20:51:05 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic 

NAME = easyfind
SRC = main.cpp 
#OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
#$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re