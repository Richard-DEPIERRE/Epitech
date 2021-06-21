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

SRC	=	src/cd.c			\
		src/create_my_env.c			\
		src/env.c			\
		src/execute_file.c			\
		src/get_path.c			\
		src/linked_list.c			\
		src/main.c			\
		src/minishell.c			\
		src/my_commands.c			\
		src/print_prompt.c			\
		src/setenv.c			\
		src/unsetenv.c			\
		lib/clean_my_string.c		\
		lib/my_strcat.c		\
		lib/my_strcmp_mod.c		\
		lib/my_strcpy.c		\
		lib/my_strlength.c		\
		lib/parse_my_string.c		\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

RM		= rm -f

NAME	= mysh

TEST 	= make -C ./tests

CFLAGS	= -W -Wall -Wextra -g3 -I./include

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