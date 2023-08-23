#include "../Includes/ft_printf.h"

void	ft_putnbr_base(int nb, int base)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_base(147483648, base);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nb, base);
	}
	else if (nb > 9)
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(nb % base, base);
	}
	else
        ft_putchar(nb + '0');
}