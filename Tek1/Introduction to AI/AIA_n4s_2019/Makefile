##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/main.c				\
		src/car_forward.c		\
		lib/clean_my_string.c	\
		lib/my_strcat.c			\
		lib/my_strcmp_mod.c		\
		lib/my_strcpy.c			\
		lib/my_strlength.c		\
		lib/parse_my_string.c	\
		src/str_to_word_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

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