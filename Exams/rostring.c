/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:02:42 by exam              #+#    #+#             */
/*   Updated: 2019/03/20 15:32:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		word_size(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		;
	return (i);
}

int		ft_strlen(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '\0')
		;
	return (i);
}

int		word_number(char *str)
{
	int		i;
	int		word;

	i = -0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			++i;
		if (str[i] != '\0' && (++word))
			i = i + word_size(&str[i]);
	}
	return (word);
}

int		ft_putstr(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
	return (0);
}

void	set_word(char *empty, char *swap)
{
	int		i;
	int		limit;

	i = -1;
	limit = word_size(swap);
	while (++i < limit)
		empty[i] = swap[i];
	empty[i] = '\0';
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (argc != 2)
		return (ft_putchar('\n'));
	if (!argv[1] || ft_strlen(argv[1]) == 0)
		return (ft_putchar('\n'));
	if (word_number(argv[1]) == 0)
		return (ft_putchar('\n'));
	if ((tab = malloc(sizeof(char *) * (word_number(argv[1]) + 1))) == NULL)
		return (-1);
	while (argv[1][i] != '\0')
	{
		while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\n' || argv[1][i] == '\t'))
			++i;
		if (argv[1][i] != '\0')
		{
			if ((tab[c] = malloc(sizeof(char) * (word_size(&argv[1][i] + 1)))) == NULL)
				return (-1);
			set_word(tab[c++], &argv[1][i]);
			i = i + word_size(&argv[1][i]);
		}
	}
	tab[c] = NULL;
	if (word_number(argv[1]) == 1)
	{
		ft_putstr(tab[0]);
		ft_putchar('\n');
		return (0);
	}
	c = 1;
	while (tab[c] != NULL)
	{
		ft_putstr(tab[c]);
		ft_putchar(' ');
		++c;
	}
	ft_putstr(tab[0]);
	ft_putchar('\n');
	return (0);
}
