/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:22:08 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 18:47:05 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_build_prec_str(int p, int len, char *str, char *s1)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (i < p - len)
			s1[i++] = '0';
		while (j < len)
		{
			s1[i] = str[j];
			j++;
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}

char				*ft_malloc_prec_o(char *str, t_params *arg)
{
	char			*s1;
	int				len;

	len = ft_strlen(str);
	if (str)
	{
		if (arg->prec == 0 && arg->flags[PREC] && str[0] == '0')
		{
			if (!arg->flags[HASH])
				return (NULL);
		}
	}
	s1 = (char *)malloc(sizeof(char) * ft_max(len, arg->prec) + 1);
	return (ft_build_prec_str(arg->prec, len, str, s1));
}

char				*ft_malloc_prec_p(char *str, t_params *arg)
{
	char			*s1;
	int				i;
	int				j;
	int				len;

	i = 0;
	j = 0;
	if (str[0] == '0' && arg->prec == 0 && arg->flags[PREC])
		str = NULL;
	len = ft_strlen(str);
	s1 = (char *)malloc(sizeof(char) * ft_max(len, arg->prec) + 1);
	return (ft_build_prec_str(arg->prec, len, str, s1));
}

int					ft_prec_s(int malloc_size, int str_length, t_params *arg)
{
	if (arg->prec > str_length)
		malloc_size = str_length;
	else if (arg->flags[PREC] == 0)
		malloc_size = str_length;
	else
		malloc_size = arg->prec;
	return (malloc_size);
}

char				*ft_malloc_prec_dux(char *str, t_params *arg)
{
	char			*s1;
	int				i;
	int				j;
	int				len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (str)
	{
		if (arg->prec == 0 && arg->flags[PREC] && str[0] == '0')
			return (NULL);
	}
	s1 = (char *)malloc(sizeof(char) * ft_max(len, arg->prec) + 1);
	return (ft_build_prec_str(arg->prec, len, str, s1));
}
