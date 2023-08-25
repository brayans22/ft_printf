#include "../Includes/util.h"

unsigned int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}