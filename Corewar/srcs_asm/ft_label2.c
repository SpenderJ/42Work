/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:23:47 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_size_file(t_asm *s_asm)
{
	int i;

	i = 0;
	while (s_asm->file[i])
		++i;
	return (i);
}

char	*ft_strjoin_set(char *s1, char *s2, char setting)
{
	int		i_s1;
	int		i_s2;
	char	*dest;

	i_s1 = -1;
	i_s2 = -1;
	if (s1 == NULL || s2 == NULL)
		ft_error(1, "s1 and/or s2.");
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		ft_error(1, "dest");
	while (s1[++i_s1])
		dest[i_s1] = s1[i_s1];
	while (s2[++i_s2])
		dest[i_s1 + i_s2] = s2[i_s2];
	dest[i_s1 + i_s2] = '\0';
	(setting == 1 || setting == 3) ? ft_strdel(&s1) : 0;
	(setting == 2 || setting == 3) ? ft_strdel(&s2) : 0;
	return (dest);
}

int		ft_find_line(t_asm *s_asm, char *s, int k, int line)
{
	int i;
	int j;

	while (s_asm->file[++line])
	{
		i = 0;
		while (s_asm->file[line][i] == 32 || s_asm->file[line][i] == '\t')
			i++;
		j = i;
		while (s_asm->file[line][j] != SEPARATOR_CHAR && s_asm->file[line][j]
			!= 32 && s_asm->file[line][j] != '\t' && s_asm->file[line][j] !=
			'\0' && s_asm->file[line][j] != COMMENT_CHAR && s_asm->file[line][j]
			!= LABEL_CHAR)
			j++;
		k = 0;
		while (s[k] && s[k] != SEPARATOR_CHAR && s[k] != COMMENT_CHAR && s[k] !=
			' ' && s[k] != '\t')
			k++;
		j = (j - i > k) ? j - i : k;
		if (ft_strncmp(s_asm->file[line] + i, s, j) == 0)
			break ;
	}
	if (line == ft_size_file(s_asm))
		ft_exit("");
	return (line);
}

int		ft_count(char *s, char t_dir, int i)
{
	int val;

	val = 0;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != ' ' && s[i] != '\t')
	{
		if (s[i] == 'r')
			val++;
		else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
			val = val + 2;
		else
		{
			if (s[i] == DIRECT_CHAR)
				val = val + 2 + (t_dir == 0 ? 2 : 0);
			else if (s[i] == LABEL_CHAR)
				val = val + 2;
		}
		while (s[i] && s[i] != COMMENT_CHAR && s[i] != ' ' && s[i] != '\t' &&
			s[i] != SEPARATOR_CHAR)
			i++;
		if (s[i] == SEPARATOR_CHAR)
			i++;
		while (s[i] == ' ' || s[i] == '\t')
			i++;
	}
	return (val);
}
