#include "../Includes/util.h"

unsigned int ft_putstr(const char *str)
{
	unsigned int len_str;

	len_str = 0;
	if (!str)
		str = PTR_NIL;
	while (*str)
	{
		len_str += ft_putchar(*str);
		str++;
	}
	return (len_str);
}