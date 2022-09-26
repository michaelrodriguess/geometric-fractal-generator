SRCS			= ./srcs/fract-ol_set.c \
				  ./srcs/fract-ol_math.c \
				  ./srcs/fract-ol_put.c \
				  ./srcs/fract-ol_error.c \
				  ./srcs/fract-ol_colors.c \
				  ./srcs/fract-ol_run.c \

NAME			= fractol

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra #-Werror
FRAME_FLAGS		= -L mlx -lmlx -framework OpenGL -framework AppKit -I ./includes
LIB_MLX_PATH	= ./mlx
PRINTF_PATH		= ./ft_printf
LIBFT_PATH		= ./ft_printf/libft/libft.a

$(NAME):
		make -C $(LIB_MLX_PATH)
		make -C $(PRINTF_PATH)
		$(CC) $(CFLAGS) $(SRCS) $(FRAME_FLAGS) $(PRINTF_PATH)/libftprintf.a $(LIBFT_PATH) -o $(NAME)

all: $(NAME)

clean:
		make clean -C $(LIB_MLX_PATH)
		make clean -C $(PRINTF_PATH)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(PRINTF_PATH)
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
