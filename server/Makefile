##
## GREGOIRE, OUNIS PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR = ./client/

SRC =	server.c			\
		clear_client.c 		\
		remove_client.c 	\
		end_connection.c 	\
		read_client.c 		\
		write_client.c 		\
		init_connection2.c 	\
		verify_windows32.c 	\
		send_message.c		\
		main.c 				\


NAME = server

LIB = -lmy -L../lib/my

INCLUDE = -I../include

CFLAGS = -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc $(INCLUDE) -o $(NAME) $(SRC) $(LIB)

debug:
	make -C ../lib/my
	gcc $(INCLUDE) -g3 -o $(NAME) $(SRC) $(LIB) $(CFLAGS)

clean:
	make clean -C ../lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ../lib/my/
	rm -f $(NAME)

re:	fclean all
