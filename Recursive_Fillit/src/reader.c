/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:36:15 by juspende          #+#    #+#             */
/*   Updated: 2017/11/14 10:36:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

void		min_max(char *str, t_point *min, t_point *max)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
	}
}

t_tetris	*get_piece(char *str, char value)
{
	t_point		*min;
	t_point		*max;
	char		**pos;
	int			i;
	t_tetris	*tetris;

	min = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5,
														max->x - min->x + 1);
		++i;
	}
	tetris = tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

t_list		*tetris_read(char *str)
{
	int			i;
	t_list		*list;
	t_tetris	*tetris;
	char		cur;

	i = 0;
	list = NULL;
	cur = 'A';
	while (str[i])
	{
		if ((tetris = get_piece(ft_strsub(str, i, 20), cur++)) == NULL)
		{
			ft_strdel(&str);
			return (free_list(list));
		}
		i += 21;
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_lstrev(&list);
	ft_strdel(&str);
	return (list);
}
