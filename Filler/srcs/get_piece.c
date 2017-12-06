/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:23:31 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 18:10:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_piece(t_piece *piece)
{
	char	*line;
	char	*tmp;
	int		i;

	get_next_line(0, &line);
	piece->ypiece = ft_atoi(&line[7]);
	i = 7 + int_len(piece->ypiece) + 1;
	piece->xpiece = ft_atoi(&line[i]);
	i = 0;
	if ((tmp = malloc(sizeof(char) * ((piece->xpiece * piece->ypiece) + 1)))
			== NULL)
		return ;
	tmp[0] = '\0';
	while (get_next_line(0, &line) > 0 && i++ != piece->ypiece)
	{
		ft_strcat(tmp, line);
		ft_strcat(tmp, "\n");
		free(line);
	}
	piece->piece = ft_strsplit(tmp, '\n');
	free(tmp);
}
