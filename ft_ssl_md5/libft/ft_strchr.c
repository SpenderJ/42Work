/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:19:42 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:19:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s != c)
		return (NULL);
	return ((char *)s);
}
