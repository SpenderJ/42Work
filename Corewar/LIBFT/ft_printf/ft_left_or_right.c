/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_or_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:57:32 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:17:36 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_is_s_right(int size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	if ((s = (char*)malloc(size + 1)))
	{
		while (i < size)
		{
			if (n)
			{
				s[i] = str[j];
				n--;
				j++;
			}
			else
				s[i] = c;
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}

char			*ft_is_s_left(int size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	if ((s = (char*)malloc(size + 1)))
	{
		while (i < size)
		{
			if (n)
			{
				s[i] = c;
				n--;
			}
			else
				s[i] = str[j++];
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}

char			*ft_is_s_perc_right(int size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	if ((s = (char*)malloc(size + 1)))
	{
		while (i < size)
		{
			if (n)
			{
				s[i] = str[j];
				n--;
				j++;
			}
			else
				s[i] = c;
			i++;
		}
		s[i] = '\0';
	}
	free(str);
	return (s);
}

char			*ft_is_s_perc_left(int size, int n, char *str, char c)
{
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	if ((s = (char*)malloc(size + 1)))
	{
		while (i < size)
		{
			if (n)
			{
				s[i] = c;
				n--;
			}
			else
				s[i] = str[j++];
			i++;
		}
		s[i] = '\0';
	}
	free(str);
	return (s);
}
