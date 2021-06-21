##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
## File description:
## Makefile
##

NAME	=	yolo

all:	$(NAME)

$(NAME):
	make -C ex00
	make -C ex01
	make -C ex06

clean:
	make clean -C ex00
	make clean -C ex01
	make clean -C ex06

fclean:	clean
	make fclean -C ex00
	make fclean -C ex01
	make fclean -C ex06

tests_run:
	make tests_run -C ex00
	make tests_run -C ex06

re:	fclean all