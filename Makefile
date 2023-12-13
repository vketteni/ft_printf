CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c  \
       main.c print/ft_print_char.c print/ft_print_format.c \
       print/ft_print_hex.c print/ft_print_int_unsigned.c  \
       print/ft_print_int.c print/ft_print_ptr.c print/ft_print_str.c \
       util/ft_is_flag.c util/ft_is_format_specifier.c \
       format/ft_get_flags.c format/ft_get_precision.c  \
       format/ft_get_specifer.c format/ft_get_min_width.c \
       checks/ft_check_char_format.c checks/ft_check_hexlc_format.c  \
       checks/ft_check_hexuc_format.c checks/ft_check_int_format.c  \
       checks/ft_check_ptr_format.c checks/ft_check_str_format.c  \
       checks/ft_check_uint_format.c checks/ft_check_validity.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	cp $(LIBFT_PATH) $(NAME)
	ar -rcv $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

.PHONY: all clean fclean re bonus 