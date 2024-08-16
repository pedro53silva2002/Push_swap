

SRCS            = push_swap_radix.c push_swap_checker.c push_swap_operations_sp.c \
					push_swap_operations_rr.c push_swap_operations_rrr.c \
					push_swap_utils.c push_swap_checker_utils.c main.c \
					push_swap_simple.c push_swap_frees.c

SRCS_BONUS		= bonus_checker/main_bonus.c bonus_checker/push_swap_checker_bonus.c \
				  bonus_checker/push_swap_checker_utils_bonus.c bonus_checker/push_swap_frees_bonus.c \
				  bonus_checker/push_swap_operations_rr_bonus.c bonus_checker/push_swap_operations_rrr_bonus.c \
				  bonus_checker/push_swap_operations_sp_bonus.c bonus_checker/push_swap_utils_bonus.c

OBJS            = $(SRCS:.c=.o)

OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

CC              = cc

RM              = rm -f

CFLAGS          =  -g -Wall -Wextra -Werror

LIBFT			= ./Libft/libft.a

NAME            = push_swap

NAME_BONUS		= checker

all:            $(NAME)

$(LIBFT):	
	$(MAKE) -C ./libft

$(NAME):        $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:         clean
	$(RM) $(NAME) $(NAME_BONUS)

re:             fclean $(NAME)

bonus:        $(NAME_BONUS)

.PHONY:         all clean fclean re bonus
