##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile that compiles your mibmy
##

SRC	=	my_putchar.c			\
		my_isneg.c			\
		my_put_nbr.c			\
		my_swap.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_getnbr.c			\
		my_is_prime.c			\
		my_revstr.c			\
		my_showmem.c			\
		my_showstr.c			\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlowcase.c			\
		my_strncat.c		 	\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_find_prime_sup.c		\
		my_str_to_word_array.c

LIBMY	=	libmy.a

INCLUDE	=	include

MY	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIBMY) $(OBJ)
	cp $(LIBMY) ../../
	cp $(MY) ../../$(INCLUDE)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIBMY)

re:	fclean all

