##
## EPITECH PROJECT, 2019
## makefile bistro-matique
## File description:
## compile and links everything together
##

NAME =		my_runner

SRC =		src/*.c

CFLAGS =	-I./include -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -o $(NAME) ./lib//my/libmy.a -lm -W -Wall -Wextra

all: $(NAME)

$(NAME):
	make re -C ./lib/my
	make clean -C ./lib/my
	gcc $(SRC) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re: fclean all