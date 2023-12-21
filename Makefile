SRCS = ft_printf.c \
	ft_tobase.c \
	ft_is_format_specifier.c \
	ft_is_flag.c \
	ft_number_length.c \
	ft_todecimal.c \
	ft_absolute.c \
	ft_check_char_format.c \
	ft_check_hex_format.c \
	ft_check_uint_format.c \
	ft_check_format_validity.c \
	ft_check_ptr_format.c \
	ft_check_str_format.c \
	ft_check_int_format.c \
	ft_print_format_string.c \
	ft_print_dec.c \
	ft_print_ptr.c \
	ft_print_str.c \
	ft_print_char.c \
	ft_initialize_print_count.c \
	ft_print_hex.c \
	ft_calculate_padding.c \
	ft_get_specifer.c \
	ft_get_format_field_attributes.c \
	ft_initialize_format_field.c \
	ft_get_flags.c \
	ft_get_precision.c \
	ft_get_min_width.c \

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
vpath %.c format checks util print
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -Rf $(OBJS)
	$(MAKE) -C ./libft clean
fclean:	clean
	rm -Rf $(NAME)
	rm -Rf ./libft/libft.a
re: fclean all
