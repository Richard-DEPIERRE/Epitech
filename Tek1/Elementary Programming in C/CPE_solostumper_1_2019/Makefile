##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/*.c

SRC2 =		tests/*.c	\
		src/hidden_p.c

OBJ	=	$(SRC:.c=.o)

NAME	=	hidenp

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

re:	fclean all

tests:
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS)
