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

SRC	=	server/server.c		\
		server/login.c		\
		server/file.c		\
		server/info.c		\
		server/logout.c		\
		server/fill.c		\
		server/misc.c		\
		server/transfer.c	\
		server/commands.c	\
		server/help.c	\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

RM		= rm -f

NAME	= myftp

TEST 	= make -C ./tests

CFLAGS	= -W -Wall -Wextra -g3 -I./include -I./include

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