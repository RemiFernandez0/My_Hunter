##
## EPITECH PROJECT, 2022
## makefile cat
## File description:
## Makefile
##

SRC		=	main.c game_view.c my_int_to_str.c init_things.c game_over.c \
			game_loop2.c

OBJ		=	$(SRC:.c=.o)

NAME 		= my_hunter

CSFML =     -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME):
				gcc -o $(NAME) $(SRC) $(CSFML)
				make clean

clean:
				rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
