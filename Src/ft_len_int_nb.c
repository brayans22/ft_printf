#include "../Includes/ft_printf.h"

size_t  ft_len_int_nb(int nb, int base)
{
    size_t len;

    len = 0;
    if (nb == 0)
        return (1);
    else if (nb <= ft_atoi(MIN_RANGE_INT_IN_STR_FORMAT))
        return (LEN_MIN_RANGE_INT);
    else if (nb > ft_atoi(MIN_RANGE_INT_IN_STR_FORMAT) && nb < 0)
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