##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/*.c

SRC2 =	tests/test_main.c		\
		tests/test_swap_elem.c	\
		tests/test_errors.c		\
		tests/test_get_nbr.c	\
		tests/test_push_swap.c	\
		src/exec.c				\
		src/push_swap.c			\
		src/my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

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
