##
## EPITECH PROJECT, 2019
## makefile bistro-matique
## File description:
## compile and links everything together
##

NAME =		my_hunter

SRC =		src/*.c

CFLAGS =	-I./include -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -o $(NAME) ./lib/libmy.a -lm -W -Wall -Wextra

all: $(NAME)

$(NAME):
	##make re -C ./lib/my
	gcc $(SRC) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all