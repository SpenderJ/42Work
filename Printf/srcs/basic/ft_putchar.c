/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:47 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 12:37:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_putchar(char c, t_flag *flag)
{
	unsigned char	d;
	size_t			i;
	char			*tmp;

	i = ft_strlen(flag->printed);
	if ((tmp = malloc(sizeof(char) * (i + 1))) == NULL)
		return ;
	d = (unsigned char)c;
	ft_strcat(tmp, flag->printed);
	free (flag->printed);
	tmp[i] = d;
	tmp[i + 1] = '\0';
	flag->printed = tmp;
	flag->charn = flag->charn + 1;
	return ;
}

void	ft_putnstr(char *str, t_flag *flag, int *c)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = ft_strlen(flag->printed);
	n = ft_strchr(str, 37);
	if ((tmp = malloc(sizeof(char) * (i + n))) == NULL)
		return ;
	ft_strcat(tmp, flag->printed);
	ft_strncat(tmp, str, n);
	free (flag->printed);
	flag->printed = tmp;
	flag->charn += n;
	*c +=(n - 1);
	return ;
}
