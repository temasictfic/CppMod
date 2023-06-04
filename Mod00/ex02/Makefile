CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = account
SRC = Account.cpp tests.cpp
#OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)
	
fclean: clean
	
re: fclean $(NAME)

.PHONY: all clean fclean re