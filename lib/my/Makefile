##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	my_putchar.c 	\
		my_putstr.c 	\
		my_put_nbr.c 	\
		my_revstr.c 	\
		my_strlen.c 	\
		my_printf.c 	\
		flag.c		\
		my_getnbr.c 	\
		my_put_hexa_max.c \
		my_put_octal.c \
		my_put_nbr2.c  \
		my_put_space.c \
		my_printf2.c	 \
		my_put_hexa_min.c \
		my_put_binary.c


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