/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_printf_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:50:15 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/19 15:50:17 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_lltoa(long long n)
{
	int		neg;
	int		i;
	char	*str;

	neg = (n < 0) ? 1 : 0;
	i = ft_llonglen((n));
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_abs(n % 10) + 48;
			n /= 10;
		}
		if (neg == 1)
			str[0] = '-';
	}
	return (str);
}

char		*ft_lltoa_base(long long n, const char *base)
{
	char			*str;
	int				baselen;
	int				i;
	long long		nc;
	int				neg;

	if (!base)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	i = 1 + neg;
	baselen = ft_strlen(base);
	nc = n;
	while (nc /= baselen)
		++i;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = base[ft_abs(n % baselen)];
		n /= baselen;
	}
	str[i] = (neg == 1) ? '-' : str[i];
	return (str);
}

char		*ft_llutoa(unsigned long long n)
{
	int		i;
	char	*str;

	i = ft_ullonglen((n));
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_abs(n % 10) + 48;
			n /= 10;
		}
	}
	return (str);
}

char		*ft_llutoa_base(unsigned long long n, const char *base)
{
	char					*str;
	int						baselen;
	int						i;
	unsigned long long		nc;

	i = 1;
	if (!base)
		return (NULL);
	baselen = ft_strlen(base);
	nc = n;
	while (nc /= baselen)
		++i;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = base[ft_abs(n % baselen)];
		n /= baselen;
	}
	return (str);
}
