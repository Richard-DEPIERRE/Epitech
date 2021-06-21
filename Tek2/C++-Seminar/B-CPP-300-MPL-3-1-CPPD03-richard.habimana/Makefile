##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

SRC	=	$(filter-out test_main.c, $(wildcard *.c))\

LIBMY=	libstring.a

INCLUDE	=	include

MY	=	string.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIBMY) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	rm -rf ./rapport *.info

fclean:	clean
	rm -f $(LIBMY)
	rm -f $(TEST_NAME)

re:	fclean all

SRC_TEST	=	$(filter-out test_main.c, $(wildcard tests/test*.c))\

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
			rm -f *.gc*
			gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TEST_FLAG)
			./unit_tests
			gcovr --exclude tests/
			gcovr -b --exclude tests/

dev:	$(SRC_TEST) $(SRC)
	rm -rf *.gc*
	rm -rf ./rapport
	gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TEST_FLAG)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
	gcovr -r . --branches --exclude tests/; lcov --capture --directory  ./ --output-file covActi.info --rc lcov_branch_coverage=1 --exclude tests/ ; genhtml -o rapport -t "MESSAGE" covActi.info --branch-coverage ;  open rapport/index.html
	rm -f $(OBJ)
	rm -f *.gc*
	rm -f $(LIBMY)
	rm -f $(TEST_NAME)
	