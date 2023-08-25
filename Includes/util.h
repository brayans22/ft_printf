#ifndef UTIL_H
# define UTIL_H

/* INCLUDES */
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdint.h>
#include "constants.h"
#include "libft.h"

/* FUNCTIONS */
size_t          ft_len_unsigned_int_nb(unsigned int nb, unsigned int base);
size_t          ft_len_uintptr(uintptr_t nb, uintptr_t base);
size_t          ft_len_int_nb(int nb, int base);
unsigned int    ft_putstr(const char *str);
unsigned int    ft_putchar(char c);
void            ft_putnbr_base_unsigned(unsigned int nb, unsigned int base_number, char *base_content);
void            ft_putnbr_decimal_base_int(int nb);
void            ft_putnbr_base_uintptr(uintptr_t nb, uintptr_t base_number, char *base_content);

#endif