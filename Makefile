# Makefile for ft_printf

NAME = ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c  # Add your ft_printf source files here
OBJS = $(SRCS:.c=.o)

# Path to the libft directory
LIBFT_DIR = ./libft

# libft library and includes
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

# Rule to compile libft library
$(LIBFT):
    @$(MAKE) -C $(LIBFT_DIR)

# Rule to compile ft_printf project
$(NAME): $(LIBFT) $(OBJS)
    $(CC) $(CFLAGS) $(LIBFT_INC) -o $@ $(OBJS) $(LIBFT_LINK)

all: $(NAME)

clean:
    @$(MAKE) -C $(LIBFT_DIR) clean
    rm -f $(OBJS)

fclean: clean
    @$(MAKE) -C $(LIBFT_DIR) fclean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
