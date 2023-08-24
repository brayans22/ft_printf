#include "../Includes/ft_printf.h"

size_t  ft_len_unsigned_int_nb(unsigned int nb, unsigned int base)
{
    size_t len;

    len = 0;
    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        nb = nb / base;
        len++;
    }
    return (len);
}