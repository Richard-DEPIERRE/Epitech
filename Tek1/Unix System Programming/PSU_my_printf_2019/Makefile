##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile lib etc
##

NAME	=	print

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	make clean -C ./lib/my

clean:
	rm -f $(OBJ)
	rm -f libmy.a

fclean:	clean
	rm -f $(NAME)

re:	fclean all
