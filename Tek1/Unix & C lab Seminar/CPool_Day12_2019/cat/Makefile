##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile cat folder
##

SRC	=	cat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L../lib/my/ -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
