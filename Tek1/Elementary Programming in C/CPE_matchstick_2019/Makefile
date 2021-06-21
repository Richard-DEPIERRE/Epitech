##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/*.c

SRC2 =	tests/test_main.c	\
		tests/test_matches.c	\
		tests/test_wrong_input.c	\
		src/matchsticks.c	\
		src/functions.c		\
		src/get_information.c	\
		src/information_player2.c	\
		src/map.c	\
		src/modify_map.c	\
		src/print.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

NAME2	=	units

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra -g3 -I./include
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info
	rm -rf rapport

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS)
	./$(NAME2)

