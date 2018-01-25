/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 15:04:23 by juspende         ###   ########.fr       */
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
	int		*med_table;

	ft_revint(a_list);
	summ = a_list[0];
	init = a_list[1];

/* Med_Table[0] == At how many med we defined */

	med_table = ft_intnew(a_list[0]);
	med_table[MED_NUM] = MED_NUM;

/* The following while is working.*/

	while (a_list[a_list[0]] != init)
	{
		if (a_list[a_list[0]] < (summ / 2) && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		else if (ft_publish(RA) != S_ERR)
			ra(a_list);
	}

/* Filling the median table with the first value */

	med_table[1] = summ;
	++med_table[MED_NUM];

/* Automatising the first half moves for the first part */

/* Reminder:
 *
** "med_table[med_table[MED_NUM]] = med_table[med_table[MED_NUM - 1]] / 2"

** Meaning:

** We set the value of next median by dividing the size of the old one by 2.
*/

	ft_printf("a_list :");
	ft_printint(a_list);
	ft_printf("b_list :");
	ft_printint(b_list);

/* Now it's time to have our main action for the 250 most little numbers (if 500 numbers sent).
** This while is waiting that everything is sorted. When everything will be
** We will set the value of med_table[2] at a negative value defined in .h
** I'm sure it cant create confusion because med can only be positive
*/

	while (med_table[1] != ENDED)
	{
/* Creating all the different med. And sorting our B_list into 'tas' */
		while (b_list[0] > 2)
		{
			++med_table[MED_NUM];
			med_table[med_table[MED_NUM]] = med_table[med_table[MED_NUM] - 1] / 2;
			init = b_list[1];
			while (b_list[b_list[0]] != init)
			{
				if (b_list[b_list[0]] > med_table[med_table[MED_NUM]] && ft_publish(PA) != S_ERR)
					pa(a_list, b_list);
				else if (ft_publish(RB) != S_ERR)
					rb(b_list);
			}
		}
/* Why decrease med_table, because there is an empty case at the end.
*/
		while (med_table[MED_NUM] == 0 && MED_NUM > 1)
			--med_table[MED_NUM];
		if (MED_NUM == 1)
			med_table[1] = ENDED;
		med_table[1] = ENDED;

/* Time to push to a_list the rest of b */

		if (med_table[MED_NUM] != 1)
			return (ft_printf("Error\n"));
		else if (ft_publish(PA) != S_ERR && ft_publish(RA) != S_ERR)
		{
			med_table[med_table[MED_NUM]] = 0;
			--med_table[MED_NUM];
			pa(a_list, b_list);
			ra(a_list);
		}

/* Finally we are going to push what we got in A under our mediane */

		while (med_table[med_table[MED_NUM]]-- > 0 && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		return (ft_printf("Succes 1\n"));

/* Where are we? We sorted the first list and pushed back our b_list into A.
** Now it's time to push what we had in b in A and put it at the beginning.
*/
	}
	ft_printf("a_list :");
	ft_printint(a_list);
	ft_printf("b_list :");
	ft_printint(b_list);
	return (SORTED);
}
