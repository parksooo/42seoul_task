CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_nbrlen.c init_print.c print_address.c \
	   print_character.c print_demical.c print_percent.c print_string.c \
	   print_lower_hexademical.c print_upper_hexademical.c \
	   print_unsigned_demical.c get_type.c num_to_string.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
$(NAME) : $(OBJS)
	ar rcs $@ $^
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : 
	make fclean 
	make all
.PHONEY: all clean fclean re
