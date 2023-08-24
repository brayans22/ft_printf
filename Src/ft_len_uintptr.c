#include "../Includes/util.h"

size_t  ft_len_uintptr(uintptr_t nb, uintptr_t base)
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