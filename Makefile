NAME = libftprintf.a

SRCS =	Src/ft_putstr.c 	\
	Src/ft_putnbr_base.c 	\
	Src/ft_atoi.c			\
	Src/ft_putchar.c		\
	Src/ft_printf.c		    \
	Src/ft_tolower.c		\
	Src/ft_strdup.c         \
	Src/ft_strlen.c         

	
INCLUDES = ./Includes

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra 

.c.o:
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}
		
$(NAME):	${OBJS} 
				ar rc ${NAME} ${OBJS} 
				ranlib ${NAME}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		
re:	fclean all

#.PHONY: all clean fclean re bonus
