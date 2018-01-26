/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 15:34:31 by juspende         ###   ########.fr       */
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

static int	parse_again_with_medians(int *a_list, int *b_list)
{
	/* This function is a really effcient solver. It is used after the medians When
	 ** we need to sort a lot of numbers by itterationg not too much.
	 */
	int		*med_table;
	int		init;
	int		sorted;

	sorted = a_list[1];
	med_table = ft_intnew(b_list[0]);
	med_table[MED_NUM] = MED_NUM;
	med_table[1] = ft_intmax(b_list);
	++med_table[MED_NUM];

	/* MED_TABLE INITIALIZATION DONE
	*/

	ft_printf("RECCURSIVE Debug of the reccursive\n");
	while (b_list[0] >= 2)
	{
		++med_table[MED_NUM];
		med_table[med_table[MED_NUM]] = (ft_intmax(b_list) + ft_intmin(b_list)) / 2;
		init = b_list[1];
		ft_printf("RECCURSIVE A_list :");
		ft_printint(a_list);
		ft_printf("RECCURSIVE Med_Table = ");
		ft_printint(med_table);
		while (b_list[b_list[0]] != init)
		{
			if (b_list[b_list[0]] > med_table[med_table[MED_NUM]] &&
					ft_publish(PA) != S_ERR)
				pa(a_list, b_list);
			else if (ft_publish(RB) != S_ERR)
				rb(b_list);
		}
		ft_printf("RECCURSIVE B_list :");
		ft_printint(b_list);
	}
	--med_table[MED_NUM];
	if (b_list[0] == 1 && ft_publish(PA) != S_ERR &&
			ft_publish(RA) != S_ERR)
	{
		pa(a_list, b_list);
		ra(a_list);
		--med_table[MED_NUM];
		med_table[med_table[MED_NUM] + 1] = 0;
	}
	else
	{
		ft_printf("RECCURSIVE Etat des listes A:");
		ft_printint(a_list);
		ft_printf("RECCURSIVE liste B:");
		ft_printint(b_list);
		ft_printf("RECCURSIVE Median :");
		ft_printint(med_table);
		return (ft_putsterr(UNKNOWN_BUG));
	}
	while (med_table[MED_NUM] > 1)
	{
		while (a_list[a_list[0]] <= med_table[med_table[MED_NUM]] && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		if (b_list[0] < LOW_SIZE_TO_SORT)
			selective_sort(a_list, b_list);
		else
		{
			parse_again_with_medians(a_list, b_list);
		}
		if (b_list[0] != EMPTY)
		{
			ft_printf("[Etat avant crash]:\n\n");
			ft_printf("Med_Table :");
			ft_printint(med_table);
			ft_printf("A_list :");
			ft_printint(a_list);
			ft_printf("B_list :");
			ft_printint(b_list);
			return (ft_putsterr(UNKNOWN_BUG));
		}
		else
		{
			--med_table[MED_NUM];
			med_table[med_table[MED_NUM] + 1] = 0;
		}
	}
	ft_printf("RECCURSIVE END A_list :");
	ft_printint(a_list);
	ft_printf("RECCURSIVE END B_list :");
	ft_printint(b_list);
	return (SORTED);
}

int		selective_sort(int *a_list, int *b_list)
{
	/* This function is a quick solver low efficient, but efficient for few numbers
	 ** It is used in case the number of number to sort is reallly little.
	 */
	int		min;
	int		c;

	while (b_list[0] != EMPTY)
	{
		c = 0;
		min = 1;
		while (++c <= b_list[0])
			b_list[c] < b_list[min] ? (min = c) : c;
		c = rr_r(b_list, c);
		min = b_list[min];
		while (c == RR && b_list[b_list[0]] != min && ft_publish(RRB) != S_ERR)
			rrb(b_list);
		while (c == R && b_list[b_list[0]] != min && ft_publish(RB) != S_ERR)
			rb(b_list);
		if (b_list[b_list[0]] == min && ft_publish(PA) != S_ERR &&
				ft_publish(RA) != S_ERR)
		{
			pa(a_list, b_list);
			ra(a_list);
		}
	}
	return (SORTED);
}

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

	/* REMINDER:
	 ** MEdians define the range, so you have to make "-"
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
		while (b_list[0] >= 2)
		{
			++med_table[MED_NUM];
			med_table[med_table[MED_NUM]] = (med_table[med_table[MED_NUM] - 1] / 2);
			ft_printf("Med_table :");
			ft_printint(med_table);
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
		--med_table[MED_NUM];

		/* We just clear the first stack in b */

		if (b_list[0] != 1)
		{
			while (a_list[a_list[0]] < summ / 2)
			{
				while (a_list[a_list[0]] < (summ / 2) && ft_publish(PB) != S_ERR)
					pb(a_list, b_list);
				if (b_list[0] < LOW_SIZE_TO_SORT)
					selective_sort(a_list, b_list);
				else
					parse_again_with_medians(a_list, b_list);
			}
			ft_printf("[END]\na_list :");
			ft_printint(a_list);
			ft_printf("b_list :");
			ft_printint(b_list);
			while(a_list[a_list[0]] > summ / 2)
			{
				while (a_list[a_list[0]] >= (summ / 2) && ft_publish(PB) != S_ERR)
					pb(a_list, b_list);
				if (b_list[0] < LOW_SIZE_TO_SORT)
					selective_sort(a_list, b_list);
				else
					parse_again_with_medians(a_list, b_list);
			}
			ft_printint(a_list);
			return (SORTED);
		}
		else if (ft_publish(PA) != S_ERR && ft_publish(RA) != S_ERR)
		{
			pa(a_list, b_list);
			ra(a_list);
			--med_table[MED_NUM];
			med_table[med_table[MED_NUM] + 1] = 0;
		}

		/* Finally we are going to push what we got in A under our mediane */

		ft_printf("Med Table :");
		ft_printint(med_table);
		ft_printf("Liste A :");
		ft_printint(a_list);
		ft_printf("Liste B :");
		ft_printint(b_list);
		while (med_table[MED_NUM] > 1)
		{
			while (a_list[a_list[0]] < med_table[med_table[MED_NUM]] && ft_publish(PB) != S_ERR)
				pb(a_list, b_list);
			if (b_list[0] < LOW_SIZE_TO_SORT)
				selective_sort(a_list, b_list);
			else
			{
				ft_printf("First launch of new feature\nb_list = ");
				ft_printint(a_list);
				parse_again_with_medians(a_list, b_list);
			}
			ft_printf("ITTERATIVE MED_TABLE =");
			ft_printint(med_table);
			if (b_list[0] != EMPTY)
			{
				ft_printf("[Etat avant crash]:\n\n");
				ft_printf("Med_Table :");
				ft_printint(med_table);
				ft_printf("A_list :");
				ft_printint(a_list);
				ft_printf("B_list :");
				ft_printint(b_list);
				return (ft_putsterr(UNKNOWN_BUG));
			}
			else if (--med_table[MED_NUM])
				med_table[med_table[MED_NUM] + 1] = 0;
		}

		/* WE MADE THE FIRST HALF MED TABLE CONTAINS ONLY 1 SIZE
		 ** WHICH IS THE TOTAL SIZE
		 */

		/* For me in future, if you need to get the last one not sorted just go to 0 and
		 ** take the next one zero, then you just have to push until 0 show up at the END
		 ** of the list, you'll know that you pushed enough
		 */


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
