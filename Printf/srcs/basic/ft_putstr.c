/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:13 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 20:03:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>

void	ft_putstr(char const *s, t_flag *flag)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!s)
		return (ft_putstr("(null)", flag));
	c = ft_strlen(flag->printed);
	i = ft_strlen((char *)s);
	if (flag->comma == 1 && flag->point <= 0)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c + 1))) == NULL)
		return ;
	printf("#DEBUG Strcat de %s + %s\n", flag->printed, s);
	ft_strcat(tmp, flag->printed);
	printf("yo\n");
	ft_strcat(tmp, (char *)s);
	printf("tg\n");
	flag->charn = flag->charn + i;
	printf("ah\n");
	free(flag->printed);
	printf("ztf [%s]\n", tmp);
	flag->printed = ft_strdup(tmp);
	printf("koi\n");
	printf("#OUT with [%s]\n", flag->printed);
	free(tmp);
}

void	ft_putoctal(char const *s, t_flag *flag)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!s)
		return (ft_putstr("(null)", flag));
	i = ft_strlen((char *)s);
	c = ft_strlen(flag->printed);
	if (flag->comma && !flag->point && !flag->diez)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c))) == NULL)
		return ;
	ft_strcat(tmp, flag->printed);
	ft_strcat(tmp, (char *)s);
	flag->charn = flag->charn + i;
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
}
