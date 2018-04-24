/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_printf_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:50:22 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/19 15:50:23 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = malloc(size + 1);
	if (str)
	{
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char*)b;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
	return (b);
}

static void	ft_strjoin_clr_free(char *tmp1, char *tmp2, int d)
{
	if (d == 0)
		free(tmp1);
	else if (d == 1)
		free(tmp2);
	else if (d == 2)
	{
		free(tmp1);
		free(tmp2);
	}
}

char		*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = a;
	tmp2 = b;
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	i = 0;
	while (a && *a)
		s[i++] = *a++;
	while (b && *b)
		s[i++] = *b++;
	s[i] = '\0';
	ft_strjoin_clr_free(tmp1, tmp2, d);
	return (s);
}
