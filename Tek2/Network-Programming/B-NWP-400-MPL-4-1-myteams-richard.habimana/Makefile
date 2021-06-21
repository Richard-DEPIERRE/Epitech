##
## EPITECH PROJECT, 2021
## B-NWP-400-MPL-4-1-myteams-richard.habimana
## File description:
## Makefile
##

CC = gcc

##################################
SRC_MAIN_CLIENT =    $(shell find client -name "*.c")

SRC_CLIENT    =        $(filter-out client/main.c, $(SRC_MAIN_CLIENT))

SRC_TEST_CLIENT =     $(wildcard client/tests/*.c)\

OBJ_MAIN_CLIENT =    $(SRC_MAIN_CLIENT:.c=.o)

NAME_CLIENT =        myteams_cli
##################################

##################################
SRC_MAIN_SERVER =    $(shell find server -name "*.c")

SRC_SERVER    =        $(filter-out server/main.c, $(SRC_MAIN_SERVER))

SRC_TEST_SERVER =     $(wildcard server/tests/*.c)\

OBJ_MAIN_SERVER =    $(SRC_MAIN_SERVER:.c=.o)

NAME_SERVER =        myteams_server
##################################

TEST_NAME =    unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -Wattributes -C -g3 -I ./include -I ./libs/myteams

NAME = myteams_server

all: $(NAME)

$(NAME): server client

client:		$(OBJ_MAIN_CLIENT)
	$(CC) $(OBJ_MAIN_CLIENT) -L./libs/myteams -lmyteams -fPIC -luuid -o $(NAME_CLIENT)

server:		$(OBJ_MAIN_SERVER)
	$(CC) $(OBJ_MAIN_SERVER) -L./libs/myteams -lmyteams -fPIC -luuid -o $(NAME_SERVER)

clean :
	rm -f $(OBJ_MAIN_CLIENT)
	rm -f $(OBJ_MAIN_SERVER)
	rm -rf *.gc*
	rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME_CLIENT)
			rm -rf $(NAME_SERVER)
			rm -rf $(TEST_NAME)
			rm -f tests/*.o

re :		fclean    \
			all