#include "../Includes/ft_printf.h"

void	ft_putstr(const char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
		}
	}
}