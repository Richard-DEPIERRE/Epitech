##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	main.c	\
		menger.c

SRC2 = 	tests/test_menger.c	\
		main.c	\
		menger.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

NAME2	=	units

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -std=gnu11 -Wall -Wextra
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS)
	./$(NAME2)
	rm -rf rapport
