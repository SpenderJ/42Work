/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:23:54 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 19:01:13 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_info_player(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->player = ft_atoi(line + 10);
	free(line);
}

void	ft_info_letter(t_info *info)
{
	info->letter = info->player ? 'O' : 'X';
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
	ft_info_player(info);
	ft_info_letter(info);
	ft_info_xy(info);
}
