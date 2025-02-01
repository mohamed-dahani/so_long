SRCS = so_long.c check_file_name.c \
       helper-functions/ft_strlen.c

OBJS = $(SRCS:.c=.o)
NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SECONDARY: ${OBJS}

.PHONY: all clean fclean re