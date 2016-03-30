CC	=	gcc
NAME	=	solve
SRC	=	main.c	\
		my_putchar.c \
		fonction.c

OBJ	=	$(SRC:%.c=%.o)
RM	=	rm -f
CFRAGS	=	-W -Wall -Wextra -Werror

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all