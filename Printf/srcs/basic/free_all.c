/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:50:35 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 14:25:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		free_main(t_flag *flag, int *i, int returned)
{
	free (flag);
	free (i);
	return (returned);
}

void	free_tab(char **tab)
{
	int		i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i] != NULL)
		free (tab[i]);
	free (tab);
}
