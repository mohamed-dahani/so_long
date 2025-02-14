SRCS = so_long.c check_file_name.c check_map.c run_window.c \
       helper-functions/ft_strlen.c helper-functions/get_next_line/get_next_line.c helper-functions/get_next_line/get_next_line_utils.c helper-functions/free_array.c helper-functions/custom_error.c \
	   helper-functions/flood_fill.c helper-functions/check_edges_map.c \
	   helper-functions/ft_printf/ft_printf.c helper-functions/ft_printf/ft_putchar.c helper-functions/ft_printf/ft_putstr.c helper-functions/ft_printf/ft_putnbr.c helper-functions/ft_printf/convert_hexa.c helper-functions/ft_printf/convert_decimal.c helper-functions/ft_itoa.c \
	   helper-functions/xpm_file_to_image.c helper-functions/draw_map.c helper-functions/find_player_and_coins.c helper-functions/cleanup.c helper-functions/move_player.c \

SRCSB = so_long_bonus.c check_file_name.c check_map_bonus.c run_window_bonus.c \
       helper-functions/ft_strlen.c helper-functions/get_next_line/get_next_line.c helper-functions/get_next_line/get_next_line_utils.c helper-functions/free_array.c helper-functions/custom_error.c \
	   helper-functions/flood_fill_bonus.c helper-functions/check_edges_map.c \
	   helper-functions/ft_printf/ft_printf.c helper-functions/ft_printf/ft_putchar.c helper-functions/ft_printf/ft_putstr.c helper-functions/ft_printf/ft_putnbr.c helper-functions/ft_printf/convert_hexa.c helper-functions/ft_printf/convert_decimal.c helper-functions/ft_itoa.c \
	   helper-functions/xpm_file_to_image_bonus.c helper-functions/print_moves_in_window_bonus.c helper-functions/draw_map_bonus.c helper-functions/find_player_and_coins_and_enemy_bonus.c helper-functions/animate_coin_bonus.c helper-functions/animate_enemy_bonus.c helper-functions/cleanup_bonus.c helper-functions/move_player_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = so_long
NAMEB = so_long_bonus
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBMLX = minilibx-linux/libmlx_Linux.a
LIBFLAGS = -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBMLX) $(LIBFLAGS)

$(NAMEB): $(OBJSB)
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBMLX) $(LIBFLAGS)

all: $(NAME)

bonus: $(NAMEB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all

.SECONDARY: ${OBJS} ${OBJSB}

.PHONY: all bonus clean fclean re