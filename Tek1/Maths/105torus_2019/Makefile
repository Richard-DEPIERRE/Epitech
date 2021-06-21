##
## EPITECH PROJECT, 2019
## makefile 105torus
## File description:
## compile lib etc
##

CC		=	gcc

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	105torus

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra  -g3 -lm
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
re:	fclean all