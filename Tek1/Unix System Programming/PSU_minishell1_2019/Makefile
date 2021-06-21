##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/*.c	\
		lib/*.c

SRC2 =	tests/test_main.c		\
		lib/*.c		\
		src/cd.c		\
		src/create_my_env.c		\
		src/env.c		\
		src/execute_file.c		\
		src/get_path.c		\
		src/my_commands.c		\
		src/print_prompt.c		\
		src/setenv.c		\
		src/unsetenv.c		\
		src/linked_list.c		\
		src/minishell.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

NAME2	=	units

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra -g3 -I./include
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	gcc tests/testssss.c -o testes
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS)
	./$(NAME2)
	rm a.out
	rm testes
	rm -rf rapport