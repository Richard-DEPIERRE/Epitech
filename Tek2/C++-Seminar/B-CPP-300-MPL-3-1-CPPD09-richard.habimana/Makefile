##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

SRC	=	Character.cpp\
		tests/test_Character.cpp\
		Warrior.cpp\
		tests/test_Warrior.cpp\
		Mage.cpp\
		tests/test_Mage.cpp\
		Priest.cpp\
		tests/test_Priest.cpp\
		Paladin.cpp\
		tests/test_Paladin.cpp


INCLUDE	=	include

OBJ	=	$(SRC:.c=.o)

all:

clean:
	rm -f *.gc*
	rm -rf ./rapport *.info

fclean:	clean
	rm -f $(TEST_NAME)

re:	fclean all

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC)
			rm -f *.gc*
			g++ -o $(TEST_NAME) $(SRC) $(TEST_FLAG)
			./unit_tests
			gcovr --exclude tests/
			gcovr -b --exclude tests/

dev:
	rm -rf *.gc*
	rm -rf ./rapport
	g++ -o $(TEST_NAME) $(SRC) $(TEST_FLAG)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
	gcovr -r . --branches --exclude tests/; lcov --capture --directory  ./ --output-file covActi.info --rc lcov_branch_coverage=1 --exclude tests/ ; genhtml -o rapport -t "MESSAGE" covActi.info --branch-coverage ;  open rapport/index.html
	rm -f *.gc*
	rm -f $(TEST_NAME)
	