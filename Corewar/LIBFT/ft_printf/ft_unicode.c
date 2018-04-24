/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:32 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 17:57:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_wchar(wchar_t wc, char wca[MB_CUR_MAX + 1])
{
	if (ft_wcharlen(wc) == 1)
	{
		wca[0] = (char)wc;
	}
	else if (ft_wcharlen(wc) == 2)
	{
		wca[0] = (char)((wc >> 6) | 0xc0);
		wca[1] = (char)((wc & 0x3f) | 0x80);
	}
	else if (ft_wcharlen(wc) == 3)
	{
		wca[0] = (char)((wc >> 12) | 0xe0);
		wca[1] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[2] = (char)((wc & 0x3f) | 0x80);
	}
	else if (ft_wcharlen(wc) == 4)
	{
		wca[0] = (char)((wc >> 18) | 0xf0);
		wca[1] = (char)(((wc >> 12) & 0x3f) | 0x80);
		wca[2] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[3] = (char)((wc & 0x3f) | 0x80);
	}
	return ((ft_wcharlen(wc) >= 1 && ft_wcharlen(wc) <= 4) ?
			ft_strdup(wca) : NULL);
}

static char	*ft_wchar_p(wchar_t wc, char wca[MB_CUR_MAX + 1], t_params *arg)
{
	if (ft_wcharlen(wc) == 1)
	{
		wca[0] = (char)wc;
	}
	else if (ft_wcharlen(wc) == 2)
	{
		wca[0] = (char)((wc >> 6) | 0xc0);
		wca[1] = (char)((wc & 0x3f) | 0x80);
	}
	else if (ft_wcharlen(wc) == 3)
	{
		wca[0] = (char)((wc >> 12) | 0xe0);
		wca[1] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[2] = (char)((wc & 0x3f) | 0x80);
	}
	else if (ft_wcharlen(wc) == 4)
	{
		wca[0] = (char)((wc >> 18) | 0xf0);
		wca[1] = (char)(((wc >> 12) & 0x3f) | 0x80);
		wca[2] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wca[3] = (char)((wc & 0x3f) | 0x80);
	}
	arg->prec -= ft_wcharlen(wc);
	return ((arg->prec >= 0) && ft_wcharlen(wc) >= 1 && ft_wcharlen(wc) <= 4 ?
			ft_strdup(wca) : NULL);
}

char		*ft_is_unicode_c(t_params *arg, int var)
{
	char	wca[MB_CUR_MAX + 1];
	wchar_t	wc;
	char	*str;

	str = NULL;
	wc = (wchar_t)var;
	ft_bzero(wca, MB_CUR_MAX + 1);
	if (var < 0 || (var >= 0xd800 && var < 0xe000) || var > 0x10ffff)
	{
		arg->flags[ERR] = 1;
		return (NULL);
	}
	if (arg->flags[PREC])
		str = ft_wchar_p(wc, wca, arg);
	else
		str = ft_wchar(wc, wca);
	if (arg->flags[ERR])
		str = NULL;
	return (str);
}
