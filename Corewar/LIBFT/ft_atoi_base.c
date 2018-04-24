/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:47:38 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/19 14:47:39 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_pow(int x, int y)
{
	int	res;

	res = 1;
	while (y--)
		res *= x;
	return (res);
}

static int	ft_strchr_pos(const char *s, int c)
{
	int		pos;

	if (!s)
		return (-1);
	pos = 0;
	while (*s && *s != c)
	{
		++pos;
		++s;
	}
	return ((*s == '\0' && c != '\0') ? -1 : pos);
}

int			ft_atoi_base(const char *s, const char *base)
{
	int	nb;
	int	baselen;
	int	sign;
	int	pos;
	int	i;

	printf("%x\n", s[7]);
	if (!s || !base)
		return (0);
	baselen = ft_strlen(base);
	i = ft_strlen(s);
	nb = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if ((*s == '+' || *s == '-') && *s++ == '-')
		sign = -1;
	while ((pos = ft_strchr_pos(base, *s++)) != -1)
		nb += pos * ft_pow(baselen, --i);
	return (nb * sign);
}
