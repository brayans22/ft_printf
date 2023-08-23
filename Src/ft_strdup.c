#include "../Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*aux;
	
	if (!(aux = (char *) malloc(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}