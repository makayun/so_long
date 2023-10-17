NAME = game
UNAME = $(shell uname -s)
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = ./libft_plus
LIBFT_LIB = $(LIBFT_DIR)/libft_plus.a
RM = rm -rf

ifeq ($(UNAME),Darwin)
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit -I/opt/X11/include -L/usr/X11/lib -lXext -lX11 -L./libft_plus -lft_plus
INCLUDES = -I/opt/X11/include -Imlx -Ilibft_plus
else
MLX_FLAGS = -L./mlx -lmlx -lX11 -lXext -lm -L./libft_plus -lft_plus
INCLUDES = -I/usr/include -Imlx -Ilibft_plus
endif

FILES = so_long \
		run_checks \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

all: $(NAME)

$(NAME): make_libft make_mlx $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

make_libft:
	make -C $(LIBFT_DIR)

make_mlx:
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: clean all

.PHONY: all make_libft make_mlx clean