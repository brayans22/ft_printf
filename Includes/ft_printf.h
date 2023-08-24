#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"

/* FORMATS CONSTANTS */
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

/* BASE CONTANTS */
#define DECIMAL_BASE 10
#define HEXADECIMAL_BASE 16

/* FUNCTIONS */
int     ft_printf(char const *format, ...);
void	ft_putchar(char c);
void	ft_putnbr_base_signed(int nb, int base);
void    ft_putnbr_base_unsigned(unsigned int nb, unsigned int base);
void	ft_putstr(const char *str);
size_t  ft_number_len_signed(int nb, int base);
size_t  ft_number_len_unsigned(unsigned int nb, unsigned int base);

#endif