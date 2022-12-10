NAME = fdf

CC = gcc
CFLAGS =

INCLUDES = -I minilibx-linux
LIBS = ./minilibx-linux/libmlx_Linux.a ./libft_extra/libft_extra.a -lX11 -lXext

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: minilibx libft $(NAME)

minilibx:
	$(MAKE) -C ./minilibx-linux

libft:
	$(MAKE) -C ./libft_extra

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft_extra clean
	$(MAKE) -C ./minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft_extra fclean
	$(MAKE) -C ./minilibx-linux clean

re: clean all

.PHONY : all clean fclean re