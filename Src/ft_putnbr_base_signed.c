#include "../Includes/ft_printf.h"

void	ft_putnbr_base_signed(int nb, int base)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_base_signed(147483648, base);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_base_signed(-nb, base);
	}
	else if (nb > 9)
	{
		ft_putnbr_base_signed(nb / base, base);
		ft_putnbr_base_signed(nb % base, base);
	}
	else
        ft_putchar(nb + '0');
}