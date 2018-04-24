/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:10:02 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/14 14:10:05 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_strjoin_clr_free(char *tmp1, char *tmp2, int d)
{
	if (d == 0)
		free(tmp1);
	else if (d == 1)
		free(tmp2);
	else if (d == 2)
	{
		free(tmp1);
		free(tmp2);
	}
}

char		*ft_b_strjoin_clr(char *a, char *b, int d, int len)
{
	char	*s;
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	ft_printf("joinclr\n");
	tmp1 = a;
	tmp2 = b;
	if (!(s = (char *)malloc(sizeof(char) * (len + len + 1))))
		return (NULL);
	i = 0;
	while (a && *a)
		s[i++] = *a++;
	while (b && *b)
		s[i++] = *b++;
	s[i] = '\0';
	ft_strjoin_clr_free(tmp1, tmp2, d);
	return (s);
}

char		*ft_b_strjoin(char *a, char *b, int len_a, int len_b)
{
	char	*s;
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;

	tmp1 = a;
	tmp2 = b;
	if (!(s = (char *)malloc(sizeof(char) * (len_a + len_b + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < len_a)
		s[i] = a[i];
	while (j < len_b)
		s[i++] = b[j++];
	s[i] = '\0';
	free(tmp1);
	return (s);
}

char	*ft_strndup_c(const char *s1, int n)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)malloc(sizeof(*t) * n + 1);
	if (!t)
		return (NULL);
	while (i < n)
	{
		t[i] = s1[i];
		i++;
	}
	t[n] = '\0';
	return (t);
}

void	print_params(t_gen *params)
{
	int		i;
	int		n;
	t_player	*tmp;

	i = 1;
	ft_printf("Print Params\n");
	ft_printf("number of players = %d\n", params->nb_players);
	ft_printf("dump = %d\n", params->dump);
	n = params->nb_players;
	tmp = params->players;
	while (i <= n)
	{
		if (!tmp)
			{
				ft_printf("Error in list of players for player %d, aborting...\n", i);
				break ;
			}
		ft_printf("-----------------------------\n");
		ft_printf("Printing info for player = %d\n", i);
		ft_printf("-----------------------------\n");
		ft_printf("·····number = %d\n", tmp->number);
		ft_printf("·····name = %s\n", tmp->name);
		ft_printf("·····comment = %s\n", tmp->comment);
		// ft_printf("·····instructions = %s\n", tmp->instructions);
		ft_printf("·····instructions = ");
		print_arg(tmp->instructions, tmp->len - PROG_NAME_LENGTH - COMMENT_LENGTH - MAGIC_NUMBER_SIZE, 'h');
		ft_printf("\n");
		ft_printf("·····length of file = %d\n", tmp->len);
		tmp = tmp->next;
		i++;
	}
}

void	print_arg(char *arg, int len, int option)
{
	int	i;
	
	i = 0;
	if (option == 'c')
	{
	// ft_printf("Print Arg\nCHAR mode\n");
	while (i < len)
	{
		if (arg[i] == 0)
			ft_printf("%c", '.');
		else
			ft_printf("%c", arg[i]);
		i++;
	}
	}
	else if (option == 'h')
	{
	// ft_printf("Print Arg\nHEX mode\n|");
	while (i < len)
	{
		if (arg[i] == 0)
			ft_printf(".");
		else
			ft_printf("%x", arg[i]);
			ft_printf("|");
		i++;
	}
	}
	else if (option == 'd')
	{
	// ft_printf("Print Arg\nDEC mode\n|");
	while (i < len)
	{
		if (arg[i] == 0)
			ft_printf(".");
		else
			ft_printf("%d", arg[i]);
			ft_printf("|");
		i++;
	}
	}
	ft_printf("\n");
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(21474);
		ft_putnbr(83648);
	}
	else
	{
		if (nb < 0 && nb > -2147483648)
		{
			ft_putchar('-');
			ft_putnbr(-nb);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		if (nb < 10 && nb >= 0)
			ft_putchar(nb + 48);
		else
			;
	}
}

int	ft_b_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
