/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:32:00 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/04 11:32:02 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put(char *str, char c, char fd, char bool_free)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	(c != 0) ? write(fd, &c, 1) : 0;
	(bool_free == 1) ? ft_strdel(&str) : 0;
}
