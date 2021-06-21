##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make build
##

SRC	=	*.c

NAME	=	rush3

all:
	gcc -o $(NAME) $(SRC) ./lib/my/*.c

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

test:
	gcc -o unit_test ./lib/my/*.c ./tests/*.c -lcriterion
