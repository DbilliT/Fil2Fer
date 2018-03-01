SRC	= putstr.c \
	  putstrprintable.c \
	  putnbr.c \
	  my_atoi.c \
	  putunsinbr.c \
	  putnbrhex.c \
	  putnbrhexup.c \
	  putnbroct.c \
	  putnbrbin.c \
	  putchr.c \
	  my_putchar.c \
	  my_intlen.c \
	  my_charcat.c \
	  my_putnstr.c \
	  my_printf.c \
	  my_putstr.c \
	  my_strndup.c \
	  my_strncpy.c \
	  my_strlen.c \
	  putpointer.c \
	  my_putnchar.c

NAME	= libmy_printf.a

CFLAGS	= -I.my_printf.h -W -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

RM	= @rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ..
	cp my_printf.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
