#include "../Includes/libft.h"

size_t	wrapped_strlen(const char * s1, size_t i)
{
	if (s1[i])
		return (i);
	return (wrapped_strlen(s1, i + 1));
}

size_t	ft_strlen(const char * s1)
{
	return (wrapped_strlen(s1, 0));
}
