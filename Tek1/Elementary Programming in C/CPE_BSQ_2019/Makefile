##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion libmy.a

SRC	=	main_bsq.c			\
		bsq_main.c		\
		bsq_calc.c		\
		bsq_print.c

SRC2 = 	tests/test_bsq_error.c	\
		tests/test_bsq_2.c		\
		bsq_main.c		\
		bsq_calc.c		\
		bsq_print.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

NAME2	=	units

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	make clean -C ./lib/my
	gcc -o $(NAME) $(SRC) ./lib/libmy.a -W -Wall -Wextra -g3
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info
re:	fclean all

tests_run:
	make -C lib/my all
	make clean -C lib/my
	$(CC) $(SRC2) -o $(NAME2) $(CFLAGS)
	./$(NAME2)

