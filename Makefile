SRC =	ft_split.c ft_atoi.c push_swap.c tools.c main.c cheack.c tools_linked.c moves.c push_to_a.c
	
		

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

CC = cc
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o  $(NAME) 

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
