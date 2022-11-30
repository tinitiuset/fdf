NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I MLX42/include/MLX42/
LIBS = ./MLX42/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	$(MAKE) -C MLX42

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C MLX42 clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C MLX42 fclean

re: clean all

.PHONY : all clean fclean re