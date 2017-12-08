/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:13:44 by juspende          #+#    #+#             */
/*   Updated: 2017/12/08 15:13:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_map(t_info *info, t_piece *piece)
{
	char	*line;
	char	*tmp;
	int		c;

	c = 0;
	if ((tmp = malloc(sizeof(char) * (((info->ymap + 2) *
							(info->xmap + 2) + 1)))) == NULL)
		return ;
	tmp[0] = '\0';
	while (get_next_line(0, &line) > 0 && c != info->ymap)
	{
		if (ft_isdigit(line[0]) == 1 && ++c)
		{
			ft_strcat(tmp, line);
			ft_strcat(tmp, "\n");
			free(line);
		}
	}
	piece->ypiece = ft_atoi(&line[7]);
	c = 7 + int_len(piece->ypiece) + 1;
	piece->xpiece = ft_atoi(&line[c]);
	free(line);
	info->map = ft_strsplit(tmp, '\n');
	free(tmp);
}

void	set_values(int i, int j, t_info *info, t_piece *piece)
{
	info->map[i][j] == info->letter_enemy ? (piece->y_enemy = i) :
		(piece->y = i);
	info->map[i][j] == info->letter_enemy ? (piece->x_enemy = j) :
		(piece->x = i);
}
