/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_printf_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:50:08 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/19 15:50:10 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] || s2[i]) && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	else if (!s1 && !s2)
		return (1);
	else
		return (0);
}

int		ft_ullonglen(unsigned long long n)
{
	int	len;

	len = 1;
	while (n /= 10)
		++len;
	return (len);
}

int		ft_llonglen(long long n)
{
	int	len;

	len = (n < 0) ? 2 : 1;
	while (n /= 10)
		++len;
	return (len);
}

int		ft_wcharlen(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 0xFF) || c < 0 || (c >= 0xd800 && c < 0xe000))
		return (0);
	else if ((c <= 0x7f && MB_CUR_MAX >= 1) || (c <= 0xff && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 0x7ff && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 0xffff && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 0x10ffff && c >= 0xe0000 && MB_CUR_MAX >= 4)
		return (4);
	return (0);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int	len;

	len = 0;
	if (wstr)
	{
		while (*wstr)
		{
			len += ft_wcharlen(*wstr);
			if (ft_wcharlen(*wstr) == 0)
			{
				return (-1);
			}
			wstr++;
		}
	}
	return (len);
}
