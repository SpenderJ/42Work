/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:23:54 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 16:11:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_info_player(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->player = ft_atoi(&line[10]);
}

void	ft_info_letter(t_info *info)
{
	info->player == 1 ? (info->letter = 'O') :
		(info->letter = 'X');
}

void	ft_info_xy(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->ymap = ft_atoi(&line[8]);
	info->xmap = ft_atoi(&line[11]);
}

void	fill_info_struct(t_info *info)
{
	ft_info_player(info);
	ft_info_letter(info);
	ft_info_xy(info);
}
