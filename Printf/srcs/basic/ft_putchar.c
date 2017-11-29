/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:47 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 22:11:10 by juspende         ###   ########.fr       */
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
	printf("#Debug Putchar entree = [%s] + [%c]\n", flag->printed, c);
	if ((tmp = malloc(sizeof(char) * (i + 2))) == NULL)
		return ;
	d = (unsigned char)c;
	printf("Ouille\n");
	ft_strcat(tmp, flag->printed);
	free(flag->printed);
	tmp[i] = (unsigned char)c;
	tmp[i + 1] = '\0';
	flag->printed = ft_strdup(tmp);
	free(tmp);
	printf("#Debug Putchar sortie = [%s]\n", flag->printed);
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
	if ((tmp = malloc(sizeof(char) * (i + n + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	ft_strncat(tmp, str, n);
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
	flag->charn += n;
	if (*c != -1)
		*c +=(n - 1);
	return ;
}
