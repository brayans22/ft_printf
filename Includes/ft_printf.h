#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"

/* CONSTANTS*/
#define DECIMAL_FORMAT 'd'
#define CHARACTER_FORMAT 'c'
#define INTEGER_FORMAT 'i'
#define FLOAT_FORMAT 'f'
#define STRING_FORMAT 's'
#define POINTER_FORMAT 'p'
#define UNSIGNED_DECIMAL_FORMAT 'u'
#define HEX_UPPER_FORMAT 'x'
#define HEX_LOWER_FORMAT 'X'
#define PERCENTAGE_FORMAT '%'
#define BACKSLAH '\\'

/* FUNCTIONS */
int ft_printf(char const *format, ...);


void	ft_putchar(char c);
void	ft_putnbr_base(int nb, int base);
void	ft_putstr(char *str);

#endif