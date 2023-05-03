SRC =	ft_split.c ft_atoi.c push_swap.c tools.c moves2.c moves3.c push_swap_great.c main.c cheack.c tools_linked.c push_to_b.c moves.c push_to_a.c
	
SRCS_B = bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utilise.c bonus/checker_line.c bonus/moves1_bonus.c bonus/moves2_bonus.c bonus/moves3_bonus.c ft_split.c ft_atoi.c push_swap.c tools.c moves2.c moves3.c push_swap_great.c cheack.c tools_linked.c push_to_b.c moves.c push_to_a.c


NAME = push_swap
CHECKER = checker
CFLAGS = -Wall -Wextra -Werror

CC = cc
	
OBJ = $(SRC:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o  $(NAME) 

bonus : $(CHECKER)

$(CHECKER): $(OBJS_B)
		$(CC) $(CFLAGS) $(OBJS_B) -o  $(CHECKER) 

clean:
	rm -f $(OBJ) $(OBJS_B)
fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all
