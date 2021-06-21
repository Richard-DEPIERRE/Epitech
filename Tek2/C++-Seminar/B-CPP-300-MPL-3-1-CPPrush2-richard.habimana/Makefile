##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

SRC	=	Box.cpp\
		GiftPaper.cpp\
		IConveyorBelt.cpp\
		IElf.cpp\
		ITable.cpp\
		LittlePony.cpp\
		Object.cpp\
		PapaXmasConveyorBeltRand.cpp\
		PapaXmasElf.cpp\
		Teddy.cpp\
		Toy.cpp\
		Wrap.cpp\
		PapaXmasTableRand.cpp\
		tests/test_main.cpp\
		tests/test_box.cpp\
		tests/test_giftPaper.cpp

SRC_MAIN	=	Box.cpp\
		GiftPaper.cpp\
		IConveyorBelt.cpp\
		IElf.cpp\
		ITable.cpp\
		LittlePony.cpp\
		Object.cpp\
		PapaXmasConveyorBeltRand.cpp\
		PapaXmasElf.cpp\
		Teddy.cpp\
		Toy.cpp\
		Wrap.cpp\
		PapaXmasTableRand.cpp\
		MyUnitTests.cpp\

SRC_SANTA	=	Box.cpp\
		GiftPaper.cpp\
		IConveyorBelt.cpp\
		IElf.cpp\
		ITable.cpp\
		LittlePony.cpp\
		Object.cpp\
		PapaXmasConveyorBeltRand.cpp\
		PapaXmasElf.cpp\
		Teddy.cpp\
		Toy.cpp\
		Wrap.cpp\
		PapaXmasTableRand.cpp\
		Santa/Santa.cpp

INCLUDE	=	include

NAME_MAIN	=	elves

NAME_SANTA	=	santa

OBJ	=	$(SRC:.c=.o)

all:
	g++ -o $(NAME_MAIN) $(SRC_MAIN) -W -Wall -Wextra
	g++ -o $(NAME_SANTA) $(SRC_SANTA) -W -Wall -Wextra

clean:
	rm -f *.gc*
	rm -rf ./rapport *.info
	rm *.xml
	rm $(NAME_MAIN) $(NAME_SANTA)

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
			@echo -en "`cat christmas 2>&-`"

dev:
	rm -rf *.gc*
	rm -rf ./rapport
	g++ -o $(TEST_NAME) $(SRC) $(TEST_FLAG)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
	gcovr -r . --branches --exclude tests/; lcov --capture --directory  ./ --output-file covActi.info --rc lcov_branch_coverage=1 --exclude tests/ ; genhtml -o rapport -t "MESSAGE" covActi.info --branch-coverage ; xdg-open rapport/index.html
	rm -f *.gc*
	rm -f $(TEST_NAME)