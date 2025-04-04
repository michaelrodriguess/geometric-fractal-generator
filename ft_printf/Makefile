SRCS	= ft_printf.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_print_digit.c \
		  ft_print_digit_u.c \
		  ft_print_lower_hex.c \
		  ft_print_upper_hex.c \
		  ft_print_point.c \
			
OBJS		= $(SRCS:.c=.o)
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
LIBC		= ar -rcs
LIBFT_PATH	= ./libft

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I -lm .

$(NAME):	$(OBJS)
		make -C $(LIBFT_PATH)
		$(LIBC) $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

all:	$(NAME)

clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

