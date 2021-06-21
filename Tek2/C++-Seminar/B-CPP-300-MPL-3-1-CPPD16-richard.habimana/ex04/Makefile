##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

all:

clean:
	rm -f *.gc*
	rm -rf ./rapport *.info

fclean:	clean
	rm -f $(TEST_NAME)
	rm -f $(NAME)

re:	fclean all

SRC_TEST	=	Parser.cpp\
				tests/test_domestic.cpp

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST)
			g++ $(TEST_FLAG) $(SRC_TEST) -o $(TEST_NAME)
			./unit_tests
			gcovr --exclude tests
			gcovr -b --exclude tests/

dev:	$(SRC_TEST) $(SRC)
	rm -rf *.gc*
	rm -rf ./rapport
	g++ -o $(TEST_NAME) $(SRC_TEST) $(TEST_FLAG)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
	gcovr -r . --branches --exclude tests/; lcov --capture --directory  ./ --output-file covActi.info --rc lcov_branch_coverage=1 --exclude tests/ ; genhtml -o rapport -t "MESSAGE" covActi.info --branch-coverage ;  open rapport/index.html
	rm -f *.gc*
	rm -f $(TEST_NAME)
	