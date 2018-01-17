/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:37:58 by juspende          #+#    #+#             */
/*   Updated: 2018/01/17 09:42:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		free_pushswap(int *a_list, int *b_list, int ret)
{
	free(a_list);
	free(b_list);
	return (ret);
}
