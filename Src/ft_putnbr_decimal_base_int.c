#include "../Includes/util.h"

void	ft_putnbr_decimal_base_int(int nb)
{
	if (nb <= ft_atoi(MIN_RANGE_INT_IN_STR_FORMAT))
	{
		ft_putstr(MIN_RANGE_INT_IN_STR_FORMAT);
        return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_decimal_base_int(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr_decimal_base_int(nb / 10);
		ft_putnbr_decimal_base_int(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}