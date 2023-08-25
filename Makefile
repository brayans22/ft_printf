NAME = libftprintf.a

SRCS =	Src/ft_putchar.c					\
		Src/ft_putstr.c 					\
		Src/ft_putnbr_base_unsigned.c		\
		Src/ft_putnbr_base_uintptr.c    	\
		Src/ft_printf.c		    			\
		Src/ft_atoi.c                       \
		Src/ft_len_unsigned_int_nb.c    	\
		Src/ft_len_uintptr.c    			\
		Src/ft_len_int_nb.c					\
		Src/print_format.c					\
		Src/ft_putnbr_decimal_base_int.c	\
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
