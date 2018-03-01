SRC	= my_atoi.c \
	  my_unsignedatoi.c \
	  my_strcmp.c \
	  my_inttostring.c \
	  my_strcat.c \
	  concatenate.c \
	  my_strlen.c

NAME	= libmy.a

CFLAGS	= -I./ -W -Werror -Wall -Wextra -ansi -pedantic

OBJ	= $(SRC:.c=.o)

RM	= @rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ..
	cp libmy.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) ../../include/libmy.h

re: fclean all
