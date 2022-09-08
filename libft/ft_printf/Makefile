SRCS	= ft_printf.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_print_digit.c \
		  ft_print_digit_u.c \
		  ft_print_lower_hex.c \
		  ft_print_upper_hex.c \
		  ft_print_point.c \
			
OBJS	= $(SRCS:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
LIBC	= ar -rcs


.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME):	$(OBJS)
		$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all


.PHONY:	all clean fclean re

