##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD01-richard-habimana
## File description:
## Makefile
##

NAME	=	tests

all:	$(NAME)

$(NAME):
	make -C ex00
	make -C ex01
	make -C ex03
	make -C ex04

clean:
	make clean -C ex00
	make clean -C ex01
	make clean -C ex03
	make clean -C ex04

fclean:	clean
	make fclean -C ex00
	make fclean -C ex01
	make fclean -C ex03
	make fclean -C ex04

tests_run:
	make tests_run -C ex00
	make tests_run -C ex01
	make tests_run -C ex03
	make tests_run -C ex04

re:	fclean all