##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/my_hunter.c			\
				src/sprite.c			\
				src/windows.c			\
				src/interaction.c		\
				src/other_fonction.c	\
				src/destroy.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_hunter

LSFML		=	-l csfml-graphics -l csfml-system

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/

$(NAME):	$(OBJ)
		make -C lib/my/
		cc -o $@ $^ $(CPPFLAGS) $(LDLIB) $(LMY) $(LSFML)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf lib/my/*.o

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f unit_tests*

re: fclean $(NAME)

unit_tests:	$(OBJ)
		gcc -o $@ $^ tests/test_printf.c $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
