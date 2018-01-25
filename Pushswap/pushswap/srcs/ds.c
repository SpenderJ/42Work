/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 13:07:36 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* ALGO EXPLANATION
** DONC
** Om commece par mettre notre max au sommet de a en decalant selon 
** le meilleur coup entre ra et rra (celui qui necessite le moins de coup
**
** Puis l'objectif est de trier en faisant des sortes de "tas".
** Donc:
** 
** On va spammer de rra pour faire defiler les nombres de RRA
**
** Si on trouve le nombre qu'on veut, niquel on le garde.
**
** Sinon on push dans b le nombre que l'on trouve.
** 
** Si le nombre que l'on cherche a deja etait push dans b.
** On va le mettre au sommet de b pour le repush dans a.
*/

int			ds(int *a_list, int *b_list)
{
	int		summ;
	int		init;
	int		c;
	int		nb;
	int		rest;

	ft_revint(a_list);
	summ = a_list[0];
	init = a_list[1];
	c = summ;
/* The following while is working.
** Making the A pile split into 2 lists of equal size
** In case of impair basic size A + 1 == B
*/
	while (a_list[a_list[0]] != init)
	{
		if (a_list[a_list[0]] < (summ / 2) && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		else if (ft_publish(RA) != S_ERR)
			ra(a_list);
	}
	while (ft_intlistsorted(a_list) != SORTED || b_list[0] != 0)
	{
		c = summ;
		while ((c /= 2) > 0 && (nb = b_list[0]) == b_list[0])
		{

			init = b_list[1];
			while (b_list[b_list[0]] != init)
			{
			if ((b_list[b_list[0]] > c) && ft_publish(PA) != S_ERR)
				pa(a_list, b_list);
			else if (ft_publish(RB) != S_ERR)
				rb(b_list);
			}
		}
		while (b_list[0] != 0 && ft_publish(PA) != S_ERR)
			pa(a_list, b_list);
		while (nb-- > 0 && ft_publish(RA) != S_ERR)
			ra(a_list);
		ft_printf("A_list:");
		ft_printint(a_list);
		ft_printf("B_list:");
		ft_printint(b_list);
		return (0);
	}
	return (SORTED);
}
