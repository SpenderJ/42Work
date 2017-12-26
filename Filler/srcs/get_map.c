/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:13:44 by juspende          #+#    #+#             */
/*   Updated: 2017/12/26 13:09:44 by juspende         ###   ########.fr       */
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
			ft_strcat(tmp, line + NUM_DEC);
			ft_strcat(tmp, "\n");
			free(line);
		}
	}
	piece->ypiece = ft_atoi(&line[6]);
	c = 6 + int_len(piece->ypiece) + 1;
	piece->xpiece = ft_atoi(&line[c]);
	free(line);
	info->map = ft_strsplit(tmp, '\n');
	free(tmp);
}

void	set_values(int i, int j, t_info *info, t_piece *piece)
{
//	dprintf(2, "Enemy = %c\n", info->letter_enemy);
	info->map[i][j] == info->letter_enemy ? (piece->y_enemy = i) :
		(piece->y = i);
	info->map[i][j] == info->letter_enemy ? (piece->x_enemy = j) :
		(piece->x = j);
//	dprintf(2, "Y enemy = %d, X enemy = %d\nMy Y = %d, My X = %d\n", piece->y_enemy, piece->x_enemy, piece->y, piece->x);
}
