##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR = ./src/

SRC =	main.c					\
		$(SRC_DIR)my_socket.c 	\

NAME = chat_online

LIB = -lmy -L./lib/my

INCLUDE = -I./include

CFLAGS = -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(INCLUDE) -o $(NAME) $(SRC) $(LIB)

debug:
	make -C ./lib/my
	gcc $(INCLUDE) -g3 -o $(NAME) $(SRC) $(LIB) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
