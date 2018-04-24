/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:49:50 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 14:57:19 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_flags(t_params *arg, char *str, int *index)
{
	if (ft_eq_char(str[*index], '#') == 1)
		return (arg->flags[HASH] = 1);
	else if (ft_eq_char(str[*index], '+') == 1)
		return (arg->flags[PLUS] = 1);
	else if (ft_eq_char(str[*index], '-') == 1)
		return (arg->flags[MINUS] = 1);
	else if (ft_eq_char(str[*index], ' ') == 1)
		return (arg->flags[SPACE] = 1);
	else if (ft_eq_char(str[*index], '0') == 1)
		return (arg->flags[ZERO] = 1);
	return (0);
}

int		ft_set_length(t_params *arg, char *str, int *index)
{
	if (ft_strnequ(str + *index, "hh", 2) == 1)
	{
		*index += 1;
		return (arg->flags[HH] = 1);
	}
	if (ft_strnequ(str + *index, "ll", 2) == 1)
	{
		*index += 1;
		return (arg->flags[LL] = 1);
	}
	else if (ft_eq_char(str[*index], 'h') == 1)
	{
		return (arg->flags[H] = 1);
	}
	else if (ft_eq_char(str[*index], 'l') == 1)
		return (arg->flags[L] = 1);
	else if (ft_eq_char(str[*index], 'j') == 1)
		return (arg->flags[J] = 1);
	else if (ft_eq_char(str[*index], 'z') == 1)
		return (arg->flags[Z] = 1);
	return (0);
}

int		ft_set_width(t_params *arg, char *str, int *index)
{
	if (ft_isdigit((int)str[*index]) == 1)
	{
		arg->width = 0;
		while (ft_isdigit((int)str[*index]) == 1)
		{
			arg->width = 10 * arg->width + (int)str[*index] - 48;
			*index += 1;
		}
		*index -= 1;
		return (1);
	}
	return (0);
}

int		ft_set_prec(t_params *arg, char *str, int *index)
{
	if (ft_eq_char(str[*index], '.') == 1)
	{
		*index += 1;
		arg->flags[PREC] = 1;
		arg->prec = 0;
		if (ft_isdigit((int)str[*index]) == 1)
		{
			arg->prec = 0;
			while (ft_isdigit((int)str[*index]) == 1)
			{
				arg->prec = 10 * arg->prec + (int)str[*index] - 48;
				*index += 1;
			}
		}
		*index -= 1;
		return (1);
	}
	return (0);
}

int		ft_flwp(t_params *arg, char *format, int *i)
{
	if (ft_set_flags(arg, format, i) == 1)
		return (1);
	else if (ft_set_length(arg, format, i) == 1)
		return (1);
	else if (ft_set_width(arg, format, i) == 1)
		return (1);
	else if (ft_set_prec(arg, format, i) == 1)
		return (1);
	return (0);
}
