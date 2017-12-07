/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:23:31 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 14:29:32 by juspende         ###   ########.fr       */
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
	while (get_next_line(0, &line) > 0 && i != piece->ypiece)
	{
		ft_strcat(tmp, line);
		ft_strcat(tmp, "\n");
		free(line);
		++i;
	}
	piece->piece = ft_strsplit(tmp, '\n');
	free(tmp);
}
