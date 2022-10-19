
NAME		=	so_long
CC			=	cc
SRCS		=	$(wildcard *.c)
OBJS		=	$(patsubst %.c, %.o, $(SRCS))
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) 

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean bonus fclean re

