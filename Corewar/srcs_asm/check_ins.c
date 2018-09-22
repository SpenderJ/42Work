/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:48:58 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:53:52 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	ft_check_dir_else(char *s, char *nbr, int *index)
{
	int i;

	i = *index;
	*nbr = *nbr - 1;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != SEPARATOR_CHAR)
		i++;
	if (s[i] && s[i] != COMMENT_CHAR)
		if (s[i++] != SEPARATOR_CHAR)
		{
			i = *index;
			return (0);
		}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*index = i;
	return (1);
}

static void	ft_check_end(char *s, char nbr, int i)
{
	if (nbr != 0)
		ft_exit("Wrong numbers of instructions.");
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] && s[i] != COMMENT_CHAR)
		ft_exit("Wrong numbers of instructions.");
}

static char	ft_dir(char *s, char *nbr, int *index)
{
	int i;

	i = *index;
	i = i + 1;
	i = (s[i] == '-') ? i + 1 : i;
	(s[i] < '0' || s[i] > '9') ? ft_exit("Wrong registre.") : 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i])
		if ((s[i] < '0' || s[i] > '9') && s[i]
			!= SEPARATOR_CHAR && s[i] != COMMENT_CHAR)
			ft_exit("Wrong registre.");
	*nbr = *nbr - 1;
	if (s[i] && s[i] != COMMENT_CHAR)
		if (s[i++] != SEPARATOR_CHAR)
		{
			i = *index;
			return (0);
		}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	*index = i;
	return (1);
}

static char	ft_direct(char *s, char *nbr, char *inst, int *index)
{
	int		i;

	i = *index;
	if (inst[*nbr - 1] != '5' && inst[*nbr - 1] != '4'
		&& inst[*nbr - 1] != '6' && inst[*nbr - 1] != '7')
		ft_exit("Wrong argument for instruction.");
	if (s[i + 1] != LABEL_CHAR)
	{
		if (ft_dir(s, nbr, &i) == 0)
		{
			*index = i;
			return (0);
		}
	}
	else
	{
		if (ft_check_dir_else(s, nbr, &i) == 0)
		{
			*index = i;
			return (0);
		}
	}
	*index = i;
	return (1);
}

void		ft_check_instruction_line(char *s, char nbr, char *inst)
{
	int i;
	int tmp;

	i = 0 + nbr;
	(inst[i] != 0) ? ft_exit("Wrong instruction") : 0;
	i = 0;
	tmp = 0;
	while (s[i] && nbr > 0 && s[i] != COMMENT_CHAR && tmp == 0)
	{
		if (s[i] == 'r')
			tmp = (ft_is_r(s, &nbr, inst, &i) == 0) ? 1 : 0;
		else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
			tmp = (ft_is_ind(s, &nbr, inst, &i) == 0) ? 1 : 0;
		else if (s[i] == LABEL_CHAR)
			tmp = (ft_is_label(s, &nbr, inst, &i) == 0) ? 1 : 0;
		else if (s[i] == DIRECT_CHAR)
			tmp = (ft_direct(s, &nbr, inst, &i) == 0) ? 1 : 0;
		else
			ft_exit("Wrong instruction.");
	}
	ft_check_end(s, nbr, i);
}
