

SRCS            = push_swap_bits.c push_swap_checker.c push_swap_operations_sp.c \
					push_swap_operations_rr.c push_swap_operations_rrr.c \
					push_swap_utils.c push_swap_checker_utils.c main.c \
					push_swap_simple.c push_swap_frees.c

OBJS            = $(SRCS:.c=.o)

CC              = cc

RM              = rm -f

CFLAGS          =  -g -Wall -Wextra -Werror

LIBFT			= ./Libft/libft.a

NAME            = push_swap

all:            $(NAME)

$(LIBFT):	
	$(MAKE) -C ./libft

$(NAME):        $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS)

fclean:         clean
	$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re bonus
