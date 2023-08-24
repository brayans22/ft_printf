#include "../Includes/util.h"

void ft_putnbr_base_unsigned(unsigned int nb, unsigned int base_number, char *base_content)
{
    if (nb >= base_number)
    	ft_putnbr_base_unsigned(nb / base_number, base_number, base_content);
    ft_putchar(base_content[nb % base_number]);
}