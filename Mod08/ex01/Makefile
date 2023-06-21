# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 02:12:33 by sciftci           #+#    #+#              #
#    Updated: 2023/06/21 01:36:52 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic 

NAME = span
SRC = main.cpp Span.cpp
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