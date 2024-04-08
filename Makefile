SRC = main.c parse.c utils.c push.c rotates.c swap.c algorithm_utils.c reverse_rotate.c algorithm.c cycles.c errors.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -I pslib.h $(OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)
	
	
clean :
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus