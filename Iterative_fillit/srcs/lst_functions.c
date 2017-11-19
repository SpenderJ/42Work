/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:20:10 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/12 04:34:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

int			ft_list_size(t_bloc *begin_list)
{
	int		i;
	t_bloc	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int			ft_list_foreach(t_bloc *begin_list, int (*f)(char **))
{
	t_bloc *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*f)(list_ptr->data) == 0)
			return (0);
		list_ptr = list_ptr->next;
	}
	return (1);
}

t_bloc		*ft_create_elem(char **data)
{
	t_bloc *element;

	element = malloc(sizeof(t_bloc));
	element->data = data;
	element->next = NULL;
	return (element);
}

void		ft_list_push_back(t_bloc **begin_list, char **data)
{
	t_bloc *elem;

	elem = *begin_list;
	if (begin_list && *begin_list)
	{
		elem = *begin_list;
		while (elem->next)
		{
			elem = elem->next;
		}
		elem->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

char		***lst_to_tab(t_bloc *bloc)
{
	char	***tab;
	int		nbtetriminos;
	int		i;

	i = -1;
	nbtetriminos = ft_list_size(bloc);
	if ((tab = (char ***)malloc(sizeof(char **) * (nbtetriminos + 1))) == NULL)
		return (NULL);
	while (++i < nbtetriminos)
	{
		tab[i] = bloc->data;
		bloc = bloc->next;
	}
	tab[i] = NULL;
	return (tab);
}
