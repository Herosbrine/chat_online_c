##
## EPITECH PROJECT, 2019
## do_op
## File description:
## do operation
##

all:	COMPILE

COMPILE:
	make -C ./server
	make -C ./client

clean:
	make clean -C ./server
	make clean -C ./client

fclean:	clean
	make fclean -C ./server
	make fclean -C ./client

re:	fclean all