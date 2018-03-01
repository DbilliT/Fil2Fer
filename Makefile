NAME	= fdf2

LIB	= -I/home/$(USER)/.froot/include/ \
	  -L/home/$(USER)/.froot/lib/ \
	  -llapin \
	  -lsfml-audio \
	  -lsfml-graphics \
	  -lsfml-window \
	  -lsfml-system \
	  -lstdc++ -ldl \
	  -lm \
	  -L./lib/ -lmy -lmy_printf

CC	= gcc

CFLAGS	= -W -Wall -Wextra -Werror -ansi -pedantic -I./include/

SRC	= src/main.c \
	  src/generate.c \
	  tcore/tekpixel.c \
	  tcore/tekline.c \
	  tcore/tekisoproject.c \
	  src/tekgetpixel.c \
	  src/to_iso.c \
	  src/tekfill.c \
	  src/display_map.c \
	  src/keypress.c \
	  src/display_figures.c \
	  src/fetch_ini.c \
	  src/fetch_shape.c \
	  src/fetch_fieldcolor.c \
	  src/to_screen_transform.c \
	  src/sphere_generator.c \
	  src/moebius_generator.c \
	  src/tore_generator.c \
	  src/cylinder_generator.c \
	  src/cone_generator.c \
	  src/paral_generator.c

INI	= sphere.ini \
	  tore.ini \
	  cylinder.ini \
	  moebius.ini \
	  cone.ini \
	  paral.ini

OBJ	= $(SRC:.c=.o)

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	make re -C lib/my/
	make clean -C lib/my/
	make re -C lib/my_printf/
	make clean -C lib/my_printf/
	$(CC) $(OBJ) $(LIB) -o $(NAME)

ini:
	./fdf2 -generate sphere 300 10
	./fdf2 -generate tore 300 20
	./fdf2 -generate moebius 300 70
	./fdf2 -generate cone 30 10
	./fdf2 -generate cylinder 300 10
	./fdf2 -generate paral 200 10

clean:
	$(RM) $(OBJ)

iniclean:
	$(RM) $(INI)

fclean:	clean iniclean
	$(RM) $(NAME)

re:	fclean all
