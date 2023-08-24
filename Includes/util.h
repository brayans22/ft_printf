#ifndef UTIL_H
# define UTIL_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>

/* FUNCTIONS */
size_t  ft_len_unsigned_int_nb(unsigned int nb, unsigned int base);
size_t  ft_len_int_nb(int nb, int base);
void	ft_putstr(const char *str);
void	ft_putchar(char c);
void    ft_putnbr_base_unsigned(unsigned int nb, unsigned int base_number, char *base_content);

#endif