#include "libft.h"

char	*ft_itoa_base(uintmax_t nbr, int base, char *abc)
{
	char	*result;
	int		i;

	i = ft_base_digitlen(nbr, base);
	if ((result = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	result[i] = '\0';
	i--;
	while (i >= 0)
	{
		result[i] = abc[nbr % base];
		nbr = nbr / base;
		i--;
	}
	return (result);
}
