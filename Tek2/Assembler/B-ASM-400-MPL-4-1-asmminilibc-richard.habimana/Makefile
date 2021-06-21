##
## EPITECH PROJECT, 2021
## MiniLibC
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.asm)

OBJ	=	$(SRC:.asm=.o)

NAME	=	libasm.so

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ld -shared $(OBJ) -o $(NAME)

%.o	:	%.asm
	nasm -f elf64 $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(LIB)

re:	fclean all