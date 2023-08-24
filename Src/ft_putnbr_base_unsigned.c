#include "../Includes/ft_printf.h"

void ft_putnbr_base_unsigned(unsigned int nb, unsigned int base)
{
    if (nb >= base)
    	ft_putnbr_base_unsigned(nb / base, base);
    ft_putchar(nb % base + '0');
}