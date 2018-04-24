/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:09:55 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/24 12:56:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			get_prog_size(char *arg)
{
	int			i;
	int			len;
	char		tab[8 + 1];

	i = -1;
	len = 8;
	while (++i < len)
	{
		tab[i] = arg[i];
		ft_printf("%d|", arg[i]);
	}
	tab[8] = '\0';
	ft_printf("\n");
	// ft_printf("%d\n", ft_atoi_base(tab, "013456789abcdef"));
}

t_player		*fill_player(char *file, t_player *player)
{
	int			i;
	int			name_start;
	int			comment_start;
	int			instructions_start;

	i = 0;
	if (check_name_header(file) == 0)
	{
		ft_printf("check_name_header failure\n");
		return (NULL);
	}
	name_start = MAGIC_NUMBER_SIZE;
	comment_start = name_start + PROG_NAME_LENGTH + 8;
	// comment_start = 140;
	// instructions_start = 2193;
	instructions_start = comment_start + COMMENT_LENGTH;

	player->name = inner_parser(file + name_start, comment_start - name_start);
	player->comment = inner_parser(file + comment_start,
			instructions_start - comment_start);
	player->instructions = inner_parser(file + instructions_start,
			player->len - instructions_start);
	player->next = NULL;
	get_prog_size(file + name_start + PROG_NAME_LENGTH);
	// player->name = NULL;
	// player->comment = NULL;
	// player->number = pl_nbr;
	// print_arg(file + name_start, comment_start - name_start);
	// print_arg(file + comment_start, instructions_start - comment_start);
	// print_arg(file, 3, 'd');
	// player->instructions = inner_parser(file, player->len);
	// player->name = name_parser(file, name_start);
	// player->comment = comment_parser(file, comment_start);
	// player->instructions = instructions_parser(file, instructions_start);
	return (player);
}

char			*get_file(t_player *player, int fd)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			set;
	int			len_a;

	set = 0;
	player->len = 0;
	str = NULL;
	len_a = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (set == 0)
		{
			str = ft_strndup_c(buf, ret);
			set = 1;
		}
		else
			str = ft_b_strjoin(str, buf, len_a, ret);
		len_a = ret;
		player->len += ret;
	}
	// print_arg(str, player->len, 'h');
	return (str);
}

t_player		*init_player(t_player *list, char *arg, int pl_nbr, int o)
{
	t_player	*new_player;
	int			fd;
	char		*file;

	if (!(new_player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) < 1)
		return (NULL);
	file = get_file(new_player, fd);
	close(fd);
	if (!file)
		return (NULL);
	new_player = fill_player(file, new_player);
	if (!new_player)
		return (NULL);
	if (list)
		new_player->next = list;
	new_player = set_player_number(new_player, list, pl_nbr, o);
	return (new_player);
}

t_player		*init_players(t_gen *params, char **av, int n_arg)
{
	t_player	*list_of_players;
	int			i;
	int			o;
	int			pl_number;

	i = 1;
	list_of_players = NULL;
	// ft_printf("n_arg = %d\n", n_arg);
	while (i <= n_arg)
	{
		pl_number = 1;
		if ((ft_strcmp("-n", av[i]) == 0))
		{
			if ((pl_number = is_numbered_player(params, i, n_arg, av)))
			{
				i +=2;
				o = 1;
			}
			else
				return (NULL);
		}
		else if (!(is_valid_player(av[i])))
			return (NULL);
		params->nb_players += 1;
		list_of_players = init_player(list_of_players, av[i], pl_number, o--);
		i++;
	}
	return (list_of_players);
}
