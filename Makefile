
NAME		=	so_long
CC			=	cc
SRCS		=	$(wildcard *.c libs/*c)
OBJS		=	$(patsubst %.c, %.o, $(SRCS))
CFLAGS		=	-Wall -Wextra -Werror -I./libs/include
RM			=	rm -f
LIBFT       =   libs/libft/libft.a
PRINTF      =   libs/printf/libftprintf.a

LIBFT_DIR  = libs/libft
PRINTF_DIR = libs/printf


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) 

fclean: clean
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean bonus fclean re

