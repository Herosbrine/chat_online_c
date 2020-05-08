##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	$(SRC_DIR)my_putchar.c 	\
		$(SRC_DIR)my_putstr.c 	\
		$(SRC_DIR)my_put_nbr.c 	\
		$(SRC_DIR)my_revstr.c 	\
		$(SRC_DIR)my_strlen.c 	\
		$(SRC_DIR)my_printf.c 	\
		$(SRC_DIR)flag.c		\
		$(SRC_DIR)my_getnbr.c 	\
		$(SRC_DIR)my_put_hexa_max.c \
		$(SRC_DIR)my_put_octal.c \
		$(SRC_DIR)my_put_nbr2.c  \
		$(SRC_DIR)my_put_space.c \
		$(SRC_DIR)my_printf2.c	 \
		$(SRC_DIR)my_put_hexa_min.c \
		$(SRC_DIR)my_put_binary.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

INCLUDE	=	-I./ -L. -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../../include/my.h

re:	fclean all