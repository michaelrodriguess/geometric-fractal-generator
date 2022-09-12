NAME			= fractol
SRCS			= fract-ol.c \
				  fract-ol_utils.c \

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra #-Werror
FRAME_FLAGS		= -L mlx -lmlx -framework OpenGL -framework AppKit
LIB_MLX_PATH	= ./mlx
LIBFT_PATH		= ./libft

$(NAME):
		make -C $(LIB_MLX_PATH)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(SRCS) $(FRAME_FLAGS) -o $(NAME)

all: $(NAME)

clean:
		make clean -C $(LIB_MLX_PATH)
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
