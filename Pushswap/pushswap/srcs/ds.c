/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/24 18:48:33 by juspende         ###   ########.fr       */
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
//	printf("FIN PREMIERE ETAPE\n");
	while (a_list[1] != t && ft_publish(RRA) != S_ERR)
	{
		rra(a_list);
		ft_printf("ETAT DES LISTES :\nListe A :\n");
		ft_printint(a_list);
		ft_printf("Liste B :\n");
		ft_printint(b_list);
//		ft_printf("On recherche %d\n", a);
		if (a_list[a_list[0]] != a && ft_publish(PB) != S_ERR &&
				find_int_position(a_list, a) != INT_DONT_EXIST)
		{
/* Deplacement de b pour inserer directement la donnee triee
** Afin d'economiser des deplacements
*/
			if (b_list[0] >= 1)
			{
				ft_printf("\n\n[NEW FEATURE]\n");
//				ft_printf("PLACEINT\n\nSEARCHED=%d\nB_LIST: ", a_list[a_list[0]]);
//				ft_printint(b_list);
				i = ft_placeint(b_list, a_list[a_list[0]]);
//				ft_printf("PLACEINT END:b_list END -> %d\n", i);
//				ft_printf("POSINT\n\n%d IS TO BE AT %dth Grade\n", a_list[a_list[0]], ft_posint(b_list, a_list[a_list[0]]));
//				ft_printf("B_LIST:");
//				ft_printint(b_list);
				n = rr_r(b_list, ft_posint(b_list, a_list[a_list[0]]));
				while (n == RR && b_list[b_list[0]] != i && ft_publish(RRB) != S_ERR)
					rrb(b_list);
				while (n == R && b_list[b_list[0]] != i && ft_publish(RB) != S_ERR)
					rb(b_list);
//				ft_printf("END OF MOVING: B_LIST:");
//				ft_printint(b_list);
				ft_printf("[END OF NEW FEATURE PB]\n\n\n");
//				if (b_list[0] > 2 && b_list[b_list[0]] > b_list[b_list[0] - 1])
//					return (printf("On a bug\n"));
			//	return (0);
			}
			pb(a_list, b_list);
			ft_printf("EOF PB\nA_list:");
			ft_printint(a_list);
			ft_printf("B_list:");
			ft_printint(b_list);
			ft_printf("\n\n");
/* On fait un petit swap pour si la liste ne contenait au'un ou au'on a un max
** sans sa mon b ne serait trie dans tout les cas ce aui diminuerait les perfs
*/
		}
		else if (find_int_position(a_list, a) == INT_DONT_EXIST &&
				(find_int_position(b_list, a) != INT_DONT_EXIST))
		{
			if (ft_publish(PB) != S_ERR)
				pb(a_list, b_list);
			if ((i = find_int_position(b_list, a)) != INT_DONT_EXIST)
				i = rr_r(b_list, i);
			while (i == RR && b_list[b_list[0]] != a && ft_publish(RRB) != S_ERR)
				rrb(b_list);
			while (i == R && b_list[b_list[0]] != a && ft_publish(RB) != S_ERR)
				rb(b_list);
			if (b_list[b_list[0]] == a && ft_publish(PA) != S_ERR)
				pa(a_list, b_list);
			--a;
		}
		else
			--a;
		ft_printf("Liste A :");
		ft_printint(a_list);
		ft_printf("Liste B :");
		ft_printint(b_list);
	}
	t = c;
	return (0);
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
//		ft_printf("Liste A :\n");
//		ft_printint(a_list);
//		ft_printf("Liste B :\n");
//		ft_printint(b_list);
	}
	return (SORTED);
}
