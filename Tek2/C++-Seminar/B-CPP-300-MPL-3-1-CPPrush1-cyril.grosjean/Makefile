##
## EPITECH PROJECT, 2019
## RUSH1 UT
## File description:
## UT
##

SRC	=

SRC_TEST =	tests/test_int_calcs.c\
			tests/test_int_comparisons.c\
			tests/test_new.c\
			tests/test_point_calcs.c\
			tests/test_vertex_calcs.c\
			tests/test_char_calcs.c\
			int.c\
			new.c\
			point.c\
			vertex.c\
			char.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	test.a

NAME_TEST	= 	unit_tests

CFLAGS 	=	-W -Wall -Werror -Wextra -g

UTFLAGS =       -l criterion --coverage

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

tests_run:
	$(RM) *.gcda *.gcno
	$(RM) unit_test.dSYM
	gcc -o $(NAME_TEST) $(UTFLAGS) $(SRC_TEST) $(CFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
		$(RM) $(OBJ)

fclean :	clean
		$(RM) $(NAME)
		$(RM) $(NAME_TEST)
		$(RM) *.gcda *.gcno
		$(RM) unit_test.dSYM

re:		fclean all