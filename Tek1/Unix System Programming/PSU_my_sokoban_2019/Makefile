##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile lib etc
##

CC		=	gcc

SRC		=	src/*.c

SRC2 = 	tests/test_position.c		\
		src/sokoban.c 			\
		src/error.c				\
		src/calculate.c			\
		src/event.c				\
		src/event_obstacles.c	\
		src/get_pos.c			\
		src/winning.c

NAME	=	my_sokoban

NAME2	=	units

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -lncurses -g3 -I./include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all


tests_run:
	$(CC) $(SRC2) -o $(NAME2) $(CFLAGS)
	./$(NAME2)