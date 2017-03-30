#### Config

NAME = rtv1
LIBS = -lm `sdl2-config --static-libs` -L./libft/ -lft
CC = gcc
INCLUDES = -I./headers/ -I./libft/includes/
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags` $(INCLUDES)
UNAME_S := $(shell uname -s)

#### Fichiers sources

SOURCES = \
	src/file_check.c \
	src/main.c \
	src/new_object.c \
	src/new_store.c \
	src/screen.c



OBJECTS = $(patsubst src/%.c, objects/%.o, $(SOURCES))

#### Regles

all: sdl libft $(NAME)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(patsubst objects/%.o, src/%.c, $@) -o $@

$(NAME): $(OBJECTS)
	@echo "Linking objects"
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	@echo "Compiled"

clean:
	@echo "Cleaning objects"
	-rm -f $(OBJECTS)

fclean: clean
	@echo "Cleaning executable"
	-rm -f $(NAME)
	-cd libft && make fclean

re: fclean all

sdl:
	-@[ `uname -s` = "Linux" ] && which sdl2-config > /dev/null || sudo apt-get install libsdl2-2.0-0 libsdl2-dev --quiet -y
	-@[ `uname -s` = "Linux" ] || which sdl2-config > /dev/null || brew install sdl2 sdl2-config

libft:
	-cd libft && make -j && make

.PHONY: all clean fclean re sdl libft
