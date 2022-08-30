NAME			= fractol
SRCS 			= test.c \
				  fract-ol.c \
				  fract-ol_utils.c \

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra
FRAME_FLAGS		= -L mlx -lmlx -framework OpenGL -framework AppKit
LIB_MLX_PATH	= ./mlx

$(NAME):
		make -C $(LIB_MLX_PATH)
		$(CC) $(CFLAGS) $(SRCS) $(FRAME_FLAGS) -o $(NAME)

all: $(NAME)

clean:
		make clean -C $(LIB_MLX_PATH)
		$(RM) $(OBJS)

fclean:	clean
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
