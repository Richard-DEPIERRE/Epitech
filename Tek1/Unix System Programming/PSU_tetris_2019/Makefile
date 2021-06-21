##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC	=	src/debug.c			\
		src/main.c			\
		src/errors.c			\
		src/get_opt.c			\
		src/print_line.c			\
		src/print_stats.c			\
		src/print_tetriminos.c			\
		src/start_game.c			\
		src/start_game2.c			\
		src/start_game3.c			\
		src/temporary.c			\
		lib/clean_my_string.c		\
		lib/my_getnbr.c		\
		lib/my_put_nbr.c		\
		lib/my_strcat.c		\
		lib/my_strcmp_mod.c		\
		lib/my_strcpy.c		\
		lib/my_strlength.c		\
		lib/parse_my_string.c		\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

RM		= rm -f

NAME	= tetris

TEST 	= make -C ./tests

CFLAGS	= -W -Wall -Wextra -g3 -I./include -lncurses -I./include

all: 		start $(NAME) end

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

test_run:
			$(TEST)
		./tests/unit_tests

retest:
	$(TEST) re
	./tests/unit_tests

clean:
		$(RM) $(OBJ)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

end:
	@echo "\033[5m\033[1m\033[32mEtat for -> $(NAME) -> compil -> OK\033[0m"

start:
	@echo "\033[5m\033[1m\033[32mWe compil your project\033[0m"

re:		fclean all