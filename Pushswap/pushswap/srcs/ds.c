/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/23 12:28:50 by juspende         ###   ########.fr       */
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

int		ds(int *a_list, int *b_list)
{
	int		n;
	int		c;
	int		t;
	int		i;
	int		a;

	n = 0;
	t = a_list[0] - 1;
	c = a_list[0];
	ft_revint(a_list);
	if ((i = find_int_position(a_list, t)) != INT_DONT_EXIST)
		i = rr_r(a_list, i);
	while (i == RR && a_list[a_list[0]] != t && ft_publish(RRA) != S_ERR)
		rra(a_list);
	while (i == R && a_list[a_list[0]] != t && ft_publish(RA) != S_ERR)
		ra(a_list);
	a = t - 1;
	while (a_list[0] != 0 && ft_publish(RRA) != S_ERR)
	{
//		printf("ETAT DES LISTES :\nListe A :\n");
//		ft_printint(a_list);
//		printf("Liste B :\n");
//		ft_printint(b_list);
//		printf("On recherche %d\n", a);
//		rra(a_list);
		if (find_int_position(a_list, a) == INT_DONT_EXIST &&
				(i = find_int_position(b_list, a)) != INT_DONT_EXIST)
		{
			i = rr_r(b_list, i);
			while (i == RR && b_list[b_list[0]] != a && ft_publish(RRB) != S_ERR)
				rrb(b_list);
			while (i == R && b_list[b_list[0]] != a && ft_publish(RB) != S_ERR)
				rb(b_list);
			if (b_list[b_list[0]] == a && ft_publish(PA) != S_ERR)
				pa(a_list, b_list);
			--a;
		}
		else if (a_list[a_list[0]] != a && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		else
			--a;
//		printf("Liste A :\n");
//		ft_printint(a_list);
//		printf("Liste B :\n");
//		ft_printint(b_list);
	}
	t = c;
	while (--t >= 0)
	{
		if ((i = find_int_position(b_list, t)) != INT_DONT_EXIST)
			i = rr_r(b_list, i);
		while (i == RR && b_list[b_list[0]] != t && ft_publish(RRB) != S_ERR)
			rrb(b_list);
		while (i == R && b_list[b_list[0]] != t && ft_publish(RB) != S_ERR)
			rb(b_list);
		if (b_list[b_list[0]] == t && ft_publish(PB) != S_ERR)
			pa(a_list, b_list);
//		printf("Liste A :\n");
//		ft_printint(a_list);
//		printf("Liste B :\n");
//		ft_printint(b_list);
	}
	return (SORTED);
}
