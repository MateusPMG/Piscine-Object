NAME = DivideNConquer
SRC = srcs/main.cpp srcs/bank.cpp srcs/account.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address,undefined

all:	$(NAME)

$(NAME): $(SRC)
		 $(CC) $(CFLAGS) $(^) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean