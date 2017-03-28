#### Config

NAME = rtv1
LIBS = -lm `sdl2-config --static-libs` -L./libft/ -lft
CC = gcc
INCLUDES = -I./headers/ -I./libft/includes/
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags` $(INCLUDES)
UNAME_S := $(shell uname -s)

#### Fichiers sources

SOURCES = \
	src/main.c \
	src/hello.c

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
	-@if [ `uname -s` = "Linux" ]; then \
		sudo apt-get install libsdl2-2.0-0 libsdl2-dev -y;\
	else \
		brew install sdl2 sdl2-config\
	; fi

libft:
	-cd libft && make

.PHONY: all clean fclean re sdl libft
