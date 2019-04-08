/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:33 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:20:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*tmp;

	if ((tmp = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
