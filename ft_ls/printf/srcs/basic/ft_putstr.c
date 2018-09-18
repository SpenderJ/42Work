/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:13 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 09:03:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>

void	ft_puttstr(char const *s, t_flag *flag)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!s)
		return (ft_puttstr("(null)", flag));
	c = fttt_strlen(flag->printed);
	i = fttt_strlen((char *) s);
	if (flag->comma == 1 && flag->point <= 0)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcattt(tmp, flag->printed);
	ft_strcattt(tmp, (char *) s);
	flag->charn = flag->charn + i;
	free(flag->printed);
	flag->printed = ft_strduuup(tmp);
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
		return (ft_puttstr("(null)", flag));
	i = fttt_strlen((char *) s);
	c = fttt_strlen(flag->printed);
	if (flag->comma && !flag->point && !flag->diez)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c) + 96)) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcattt(tmp, flag->printed);
	ft_strcattt(tmp, (char *) s);
	flag->charn = flag->charn + i;
	free(flag->printed);
	flag->printed = ft_strduuup(tmp);
	free(tmp);
}

void	ft_puts(char *str, t_flag *flag)
{
	empty_buffer(flag);
	if (!str)
		return ;
	write(1, str, fttt_strlen(str));
	flag->charn += fttt_strlen(str);
}

void	ft_putnstr_free(void *str, t_flag *flag, int *c)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = fttt_strlen(flag->printed);
	n = ft_strchrrrr(str, 37);
	if ((tmp = malloc(sizeof(char) * (i + n + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcattt(tmp, flag->printed);
	ft_strnncat(tmp, str, n);
	free(flag->printed);
	flag->printed = ft_strduuup(tmp);
	free(tmp);
	flag->charn += n;
	if (*c != -1)
		*c += (n - 1);
	free(str);
	return ;
}

int		ft_puttsterr(char *str)
{
	if (!str)
		return (-1);
	write(2, str, fttt_strlen(str));
	return (ERROR);
}
