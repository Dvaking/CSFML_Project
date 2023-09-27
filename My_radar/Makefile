##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/main.c							\
				src/toolbox/destroy.c				\
				src/toolbox/help.c					\
				src/check_error/error_handing.c		\
				src/graphical/sprite.c				\
				src/graphical/texture.c				\
				src/graphical/windows.c				\
				src/graphical/square.c				\
				src/graphical/circle.c				\
				src/file/check_file.c				\
				src/file/file_data.c				\
				src/file/how_many_tower_plane.c


OBJ			=	$(SRC:.c=.o)

NAME		=	my_radar

LSFML		=	-l csfml-graphics -l csfml-system -lm

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/

$(NAME):	$(OBJ)
		make -C lib/my/
		cc -o $@ $^ $(CPPFLAGS) $(LSFML) $(LDLIB) $(LMY)

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
		gcc -o $@ $^ tests/test_my_radar.c $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
