NAME = game
UNAME = $(shell uname -s)
CC = @clang
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = ./libft_plus
LIBFT_LIB = $(LIBFT_DIR)/libft_plus.a
RM = @rm -rf

ifeq ($(UNAME),Darwin)
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit -I/opt/X11/include -L/usr/X11/lib -lXext -lX11 -L./libft_plus -lft_plus
INCLUDES = -I/opt/X11/include -Imlx -Ilibft_plus
else
MLX_FLAGS = -L./mlx -lmlx -lX11 -lXext -lm -L./libft_plus -lft_plus
INCLUDES = -I/usr/include -Imlx -Ilibft_plus
endif

FILES = so_long \
		sl_map_checks \
		sl_frees \
		sl_map_init \
		sl_is_there_the_way \
		sl_map_render \
		sl_utils \
		sl_assets_init \
		sl_victory \
		sl_movement \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c $(FILES)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

$(NAME): so_long.h $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	@echo "Game compiled"

$(LIBFT_LIB):
	@make -s -C $(LIBFT_DIR)

$(MLX_LIB):
	@make --quiet -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

re: clean $(NAME)

fre: fclean $(NAME)

.PHONY: all clean fclean re fre