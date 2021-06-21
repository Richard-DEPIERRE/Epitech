##
## EPITECH PROJECT, 2021
## Piscine_Haskell
## File description:
## Makefile
##

SRC	=	PushSwapChecker.hs

NAME	=	pushswap_checker

GHC	=	ghc

all:	$(NAME)

$(NAME):
	$(GHC) $(SRC) -o $(NAME)

clean:
	rm -f *.hi *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all