/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:23:54 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 15:34:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_info_player(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	ft_atoi(line + 10) == 1 ? (info->player = P1) :
		(info->player = P2);
	free(line);
}

void	ft_info_letter(t_info *info)
{
	info->letter = info->player ? 'O' : 'X';
	info->letter == 'O' ? (info->letter_enemy = 'X') :
		(info->letter_enemy = 'O');
}

void	ft_info_xy(t_info *info)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	info->ymap = ft_atoi(&line[8]);
	i = 8 + int_len(info->ymap) + 1;
	info->xmap = ft_atoi(&line[i]);
	free(line);
}

void	fill_info_struct(t_info *info)
{
	if (info->player == 'N')
		ft_info_player(info);
	ft_info_letter(info);
	ft_info_xy(info);
}
