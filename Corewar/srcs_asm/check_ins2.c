/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ins2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:49:26 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	ft_is_r(char *s, char *nbr, char *inst, int *index)
{
	int i;

	i = *index;
	if (inst[*nbr - 1] != '6' && inst[*nbr - 1] != '2' && inst[*nbr - 1]
		!= '3' && inst[*nbr - 1] != '7')
		ft_exit("Wrong argument for instruction.");
	i++;
	(s[i] < '0' || s[i] > '9') ? ft_exit("Wrong registre.") : 0;
	if (ft_atoi(s + i) > 99 || ft_atoi(s + i) < 0)
		ft_exit("Wrong registre.");
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*nbr = *nbr - 1;
	if (s[i] && s[i] != COMMENT_CHAR)
		if (s[i++] != SEPARATOR_CHAR)
		{
			*index = i;
			return (0);
		}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*index = i;
	return (1);
}

char	ft_is_ind(char *s, char *nbr, char *inst, int *index)
{
	int i;

	i = *index;
	(inst[*nbr - 1] != '5' && inst[*nbr - 1] != '1' && inst[*nbr - 1]
		!= '3' && inst[*nbr - 1] != '7') ? ft_exit("Wrong.") : 0;
	*nbr = *nbr - 1;
	i = (s[i] == '-') ? i + 1 : i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i])
		if ((s[i] < '0' || s[i] > '9') && s[i] != SEPARATOR_CHAR && \
		s[i] != COMMENT_CHAR)
			ft_exit("Wrong registre.");
	if (s[i] && s[i] != COMMENT_CHAR)
		if (s[i++] != SEPARATOR_CHAR)
		{
			*index = i;
			return (0);
		}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*index = i;
	return (1);
}

char	ft_is_label(char *s, char *nbr, char *inst, int *index)
{
	int i;

	i = *index;
	if (inst[*nbr - 1] != '5' && inst[*nbr - 1] != '1' && inst[*nbr - 1]
		!= '3' && inst[*nbr - 1] != '7')
		ft_exit("Wrong argument for instruction.");
	i++;
	*nbr = *nbr - 1;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != SEPARATOR_CHAR)
		i++;
	if (s[i] && s[i] != COMMENT_CHAR)
		if (s[i++] != SEPARATOR_CHAR)
		{
			*index = i;
			return (0);
		}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*index = i;
	return (1);
}
