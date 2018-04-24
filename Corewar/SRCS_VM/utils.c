/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:10:02 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/24 12:56:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

char		*ft_b_strjoin_clr(char *a, char *b, int d, int len)
{
	char	*s;
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	ft_printf("joinclr\n");
	tmp1 = a;
	tmp2 = b;
	if (!(s = (char *)malloc(sizeof(char) * (len + len + 1))))
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

char		*ft_b_strjoin(char *a, char *b, int len_a, int len_b)
{
	char	*s;
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;

	tmp1 = a;
	tmp2 = b;
	if (!(s = (char *)malloc(sizeof(char) * (len_a + len_b + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < len_a)
		s[i] = a[i];
	while (j < len_b)
		s[i++] = b[j++];
	s[i] = '\0';
	free(tmp1);
	return (s);
}

char	*ft_strndup_c(const char *s1, int n)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)malloc(sizeof(*t) * n + 1);
	if (!t)
		return (NULL);
	while (i < n)
	{
		t[i] = s1[i];
		i++;
	}
	t[n] = '\0';
	return (t);
}
