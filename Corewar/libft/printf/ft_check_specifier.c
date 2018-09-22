/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:18:27 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:18:29 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_find_specifier_2(char **str, t_arg *param)
{
	if (**str == 'u' || **str == 'U' || **str == 'x' || **str == 'b'
			|| **str == 'X' || **str == 'C' || **str == '%' || **str == 'c')
	{
		if (**str == 'u')
			param->spec = u;
		else if (**str == 'U')
			param->spec = U;
		else if (**str == 'x')
			param->spec = x;
		else if (**str == 'X')
			param->spec = X;
		else if (**str == 'C')
			param->spec = C;
		else if (**str == 'c')
			param->spec = c;
		else if (**str == '%')
			param->spec = percent;
		else if (**str == 'b')
			param->spec = b;
	}
	else
		param->spec = wrong;
	param->specifier = **str;
}

int		ft_find_specifier(char **str, t_arg *param)
{
	if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd'
			|| **str == 'D' || **str == 'i' || **str == 'o' || **str == 'O')
	{
		if (**str == 's')
			param->spec = s;
		else if (**str == 'S')
			param->spec = S;
		else if (**str == 'p')
			param->spec = p;
		else if (**str == 'd')
			param->spec = d;
		else if (**str == 'D')
			param->spec = D;
		else if (**str == 'i')
			param->spec = i;
		else if (**str == 'o')
			param->spec = o;
		else if (**str == 'O')
			param->spec = O;
		param->specifier = **str;
	}
	else
		ft_find_specifier_2(str, param);
	return (param->spec);
}
