SRCS = so_long.c check_file_name.c check_map.c run_window.c \
       helper-functions/ft_strlen.c helper-functions/get_next_line/get_next_line.c helper-functions/get_next_line/get_next_line_utils.c helper-functions/free_array.c helper-functions/custom_error.c \
	   helper-functions/flood_fill.c helper-functions/check_edges_map.c \
	   helper-functions/ft_printf/ft_printf.c helper-functions/ft_printf/ft_putchar.c helper-functions/ft_printf/ft_putstr.c helper-functions/ft_printf/ft_putnbr.c helper-functions/ft_printf/convert_hexa.c helper-functions/ft_printf/convert_decimal.c

OBJS = $(SRCS:.c=.o)
NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBMLX = minilibx-linux/libmlx_Linux.a
LIBFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $(NAME) $(OBJS) $(LIBMLX)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SECONDARY: ${OBJS}

.PHONY: all clean fclean re