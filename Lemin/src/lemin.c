/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:57 by juspende          #+#    #+#             */
/*   Updated: 2018/03/22 13:58:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	usage(char *av[])
{
	ft_printf(
		"usage: %s [-hvsg] [-i <filename>] [-o <filename>]\n"
		"  -h              Show this help.\n"
		"  -s              Execute the program step by step (imply -v).\n"
		"  -v              Output some verbose to the standard error output.\n"
		"  -g              Enable the ncurses GUI.\n"
		"  -i <filename>   Use `filename` as input.\n"
		"  -o <filename>   Output standard output to `filename`.\n",
		av[0]);
	return (EXIT_FAILURE);
}

static int	finalize(t_lemin *lemin, t_map *rooms, int ecode)
{
	if (lemin->input != STDIN_FILENO)
		close(lemin->input);
	if (lemin->output != STDOUT_FILENO)
		close(lemin->output);
	ft_sdsdtor(&lemin->map);
	ft_mapdtor(rooms, (t_dtor)ft_pfree, (t_dtor)lemin_vertexdtor);
	return (ecode);
}

static int	tryopen(t_lemin *lemin, char const *filename, int flags, int *out)
{
	int fd;

	if (*out > 2)
		close(*out);
	if ((fd = open(filename, flags, 0666)) < 0)
		return (lemin_error(lemin, "%s: %m\n", filename));
	*out = fd;
	return (YEP);
}

static int	opt(t_lemin *l, int ac, char *av[])
{
	int opt;

	g_optind = 1;
	l->prg = av[0];
	while ((opt = ft_getopt(ac, av, "hvsgi:o:")) != WUT)
		if (opt == 'h' || !ft_strchr("vsgio", opt))
			return (NOP);
		else if (opt == 'v')
			l->options |= OPT_VERB;
		else if (opt == 's')
			l->options |= (OPT_STEP | OPT_VERB);
		else if (opt == 'g')
			l->options |= OPT_NGUI;
		else if (opt == 'i')
		{
			if (tryopen(l, g_optarg, O_RDONLY, &l->input))
				return (NOP);
		}
		else if (opt == 'o')
		{
			if (tryopen(l, g_optarg, O_WRONLY | O_CREAT | O_TRUNC, &l->output))
				return (NOP);
		}
	return (g_optind < ac);
}

int			main(int ac, char *av[])
{
	t_lemin		lemin;
	t_map		graph;
	int			ants;

	ft_bzero(&lemin, sizeof(t_lemin));
	ft_mapctor(&graph, g_strhash, sizeof(char *), sizeof(t_vertex));
	lemin.input = STDIN_FILENO;
	lemin.output = STDOUT_FILENO;
	if (opt(&lemin, ac, av))
	{
		if ((g_optind < ac) && (lemin.options & OPT_VERB))
			lemin_error(&lemin, "%s: Unexpected argument.\n", av[g_optind]);
		finalize(&lemin, &graph, EXIT_FAILURE);
		return (usage(av));
	}
	if (lemin_parse(&lemin, &graph, &ants) || lemin_valid(&lemin, &graph))
		return (finalize(&lemin, &graph, EXIT_FAILURE));
	if (lemin.map.len)
		ft_dprintf(lemin.output, lemin.map.buf);
	lemin_guiinit(&lemin, &graph);
	lemin.ants = ants;
	ft_dprintf(lemin.output, "\n");
	lemin_solve(&lemin, &graph, 0);
	lemin_guiexit();
	return (finalize(&lemin, &graph, EXIT_SUCCESS));
}
