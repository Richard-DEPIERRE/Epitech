##
## EPITECH PROJECT, 2021
## cpp_rush3
## File description:
## Makefile
##

SRC_MAIN =	./main.cpp							\
			./Errors/Error.cpp					\
			./Errors/ErrorFile.cpp				\
			./Errors/ErrorCircuit.cpp			\
			./Parsing/Parsing.cpp				\
			./Circuit/Circuit.cpp				\
			./Circuit/ComponentFactory.cpp		\
			./Component/Pin.cpp					\
			./Component/Component.cpp			\
			./Component/Input.cpp				\
			./Component/DefaultInput.cpp		\
			./Component/Output.cpp				\
			./Component/Clock.cpp				\
			./Component/True.cpp				\
			./Component/False.cpp				\
			./Component/4001.cpp				\
			./Component/4008.cpp				\
			./Component/4011.cpp				\
			./Component/4013.cpp				\
			./Component/4017.cpp				\
			./Component/4030.cpp				\
			./Component/4040.cpp				\
			./Component/4069.cpp				\
			./Component/4071.cpp				\
			./Component/4081.cpp				\
			./Component/4514.cpp				\
			./Component/4512.cpp				\


CC =	g++

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		nanotekspice

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf *.o
	rm -rf tests/*.o*

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re