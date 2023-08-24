#include "../Includes/util.h"

void ft_putnbr_base_uintptr(uintptr_t nb, uintptr_t base_number, char *base_content)
{
    if (nb >= base_number)
	{
		ft_putnbr_base_uintptr(nb / base_number, base_number, base_content);
		ft_putnbr_base_uintptr(nb % base_number, base_number, base_content);
	}
	else
	    ft_putchar(base_content[nb]);
}