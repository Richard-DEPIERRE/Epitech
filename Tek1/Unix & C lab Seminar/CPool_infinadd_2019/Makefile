##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile that compiles your mibmy
##

SRC	=	infin_add.c		\
		infin_add2.c	\
		infin_add3.c	\
		error_add.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all: 	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o infin_add infin_add.c -L./lib/my/ -lmy -g3
	make fclean -C ./lib/my

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
