NAME = pipex

SRC = pipex.c ft_split.c ft_substr.c utils1.c utils2.c checks.c errors.c childs.c

CC = cc

OBJ =$(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
