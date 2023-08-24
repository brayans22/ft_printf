#include "../Includes/ft_printf.h"

size_t  ft_number_len_signed(int nb, int base)
{
    size_t len;

    len = 0;
    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        nb = -nb;
        len++; 
    }
    while (nb > 0)
    {
        nb = nb / base;
        len++;
    }
    return (len);
}