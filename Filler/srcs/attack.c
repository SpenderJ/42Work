/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:30:10 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 15:52:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		algo_down_left(t_info *info, int i, int j)
{
	while (--i > 0 && (j = -1) == -1)
		while (++j < info->xmap)
			if (try_token(info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (Attack_Succes_Time_To_Launch_The_New_map);
	return (Keep_Going);
}

static int		algo_up_right(t_info *info, int i, int j)
{
	while (++i < info->ymap && (j = info->xmap + 1) == info->xmap + 1)
		while (--j > 0)
			if (try_token(info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (Attack_Succes_Time_To_Launch_The_New_map);
	return (Keep_Going);
}

static int		algo_down_right(t_info *info, int i, int j)
{
	while (--i > 0 && (j = (info->xmap + 1) == info->xmap + 1))
		while (--j > 0)
			if (try_token(info, i, j) == 1 && (info->finalx = j) == j && 
					(info->finaly = i) == i)
				return (Attack_Succes_Time_To_Launch_The_New_map);
	return (Keep_Going);
}

static int		algo_up_left(t_info *info, int i, int j)
{
	while (++i < info->ymap && (j = -1) == -1)
		while (++j < info->xmap)
			if (try_token(info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (Attack_Succes_Time_To_Launch_The_New_map);
	return (Keep_Going);
}

int				algo(t_info *info)
{
	if (info->attack == UPLEFT)
		return (algo_up_left(info, -1, 0));
	else if (info->attack == DOWNRIGHT)
		return (algo_down_right(info, info->ymap + 1, 0));
	else if (info->attack == UPRIGHT)
		return (algo_up_right(info, -1, 0));
	else if (info->attack == DOWNLEFT)
		return (algo_down_left(info, info->ymap + 1, 0));
	else
		return (Keep_Going);
}
