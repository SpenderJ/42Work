/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:23:31 by juspende          #+#    #+#             */
/*   Updated: 2017/12/26 13:09:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_piece(t_piece *piece)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = malloc(sizeof(char) * (((piece->xpiece + 2) *
							(piece->ypiece + 2)) + 1))) == NULL)
		return ;
	tmp[0] = '\0';
	while (i != piece->ypiece && get_next_line(0, &line))
	{
		++i;
		ft_strcat(tmp, line);
		ft_strcat(tmp, "\n");
		free(line);
	}
	piece->piece = ft_strsplit(tmp, '\n');
	free(tmp);
}
