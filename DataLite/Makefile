NAME = DataLite
CC = g++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -std=c++11 -g

# Find all .cpp files and generate corresponding .o files
SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

