/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:53:12 by juspende          #+#    #+#             */
/*   Updated: 2018/03/22 14:11:36 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#define ERR0 "Missing x coord in `%s`\n"
#define ERR1 "Invalid x coord `%s`\n"
#define ERR2 "Missing y coord in `%s`\n"
#define ERR3 "Invalid y coord `%s`\n"
#define ERR5 "Missing line after `%s` attribute\n"
#define ERR6 "Expected `-` in edge `%s`\n"
#define ERR7 "Invalid edge `%s`\n"
#define ERR8 "Edge unknowns rooms `%s`\n"
#define ERR9 "Duplicate edge `%s`\n"
#define ERRA "Invalid room identifier `%s`\n"
#define ERRB "Duplicate room identifier `%s`\n"
#define ERRC "Expected ants got `%s`\n"
#define ERRD "Invalid ants `%s`\n"
#define ERRE "Invalid Name `%s`\n"

static int	parsexy(t_lemin *lemin, char *op, int i, t_vertex *v)
{
	errno = 0;
	if (op[i++] == '-')
		return (NOP);
	while (op[i] && ft_isspace(op[i]))
		++i;
	if (!ft_isdigit(op[i]))
		return (lemin_error(lemin, ERR0, op));
	if ((v->x = ft_atoi(op + i)) < 0 || errno || v->x > COORD_LIMIT)
		return (lemin_error(lemin, ERR1, op + i));
	while (op[i] && ft_isdigit(op[i]))
		++i;
	while (op[i] && ft_isspace(op[i]))
		++i;
	if (!ft_isdigit(op[i]))
		return (lemin_error(lemin, ERR2, op));
	if ((v->y = ft_atoi(op + i)) < 0 || errno || v->x > COORD_LIMIT)
		return (lemin_error(lemin, ERR3, op + i));
	return (YEP);
}

static int	parseattr(t_lemin *lemin, char **op, t_vertex *vertex)
{
	if (!ft_strcmp((*op) + 2, "end"))
		vertex->kind = VERTEX_END;
	else if (!ft_strcmp((*op) + 2, "start"))
		vertex->kind = VERTEX_START;
	if (ft_getsln(lemin->input, op, &lemin->map) != 1)
		return (lemin_error(lemin, ERR5, op));
	return (YEP);
}

static int	parseedge(t_lemin *lemin, char *op, t_map *graph, char *from)
{
	int		i;
	size_t	len;

	i = 0;
	while (op[i] && op[i] != '-')
		++i;
	if (op[i] != '-')
	{
		free(from);
		return (lemin_error(lemin, ERR6, op));
	}
	if (!(len = ft_strlen(op + ++i)) || *(op + i + len) ||
		!ft_stris(op + i, ft_isalnum))
		return (ft_free(from, lemin_error(lemin, ERR7, op)));
	if (!ft_strcmp(from, op + i))
		return (ft_free(from, YEP));
	if ((i = lemin_edgeadd(graph, from, op + i)))
		return (ft_free(from, lemin_error(lemin, i == 1 ? ERR8 : ERR9, op)));
	free(from);
	return (YEP);
}

static int	parsevertex(t_lemin *l, char **op, t_map *g)
{
	int			i;
	t_vertex	v;

	i = 0;
	lemin_vertexctor(&v);
	if (*op && !ft_strncmp(*op, "##", 2) && parseattr(l, op, &v))
		return (OUF);
	if (!*op || **op == ' ' || **op == '\0' || **op == 'L' || **op == '#')
		return (**op == '\n' || !**op ? NOP : lemin_error(l, ERRE, *op));
	while ((*op)[i] != '\0' && ft_isalnum((*op)[i]))
		++i;
	if (!i || (*op)[i] == '\0' || !ft_isalnum((*op)[i - 1]))
		return (lemin_error(l, ERRA, *op));
	if ((v.id = malloc(sizeof(char) * (i + 1))) == NULL)
		return (WUT);
	i = -1;
	while ((*op)[++i] != '\0' && ft_isalnum((*op)[i]))
		v.id[i] = (*op)[i];
	v.id[i] = '\0';
	if ((i = parsexy(l, *op, i, &v)))
		return (i == OUF ? ft_free(v.id, OUF) : parseedge(l, *op, g, v.id));
	if (lemin_vertexadd(g, v))
		return (ft_free(v.id, lemin_error(l, ERRB, *op)));
	return (YEP);
}

int			lemin_parse(t_lemin *lemin, t_map *graph, int *ants)
{
	char	*op;
	int		ret;

	op = NULL;
	while ((ret = ft_getsln(lemin->input, &op, &lemin->map)))
	{
		if (ret < 0)
			return (lemin_error(lemin, "%m\n"));
		else if (op && *op == '#' && *(op + 1) != '#')
			continue ;
		else if (!op || !ft_isdigit(*op))
			return (ft_free(op, lemin_error(lemin, ERRC, op)));
		ret = 0;
		break ;
	}
	if (!op || (*ants = ft_atoi(op)) < 0 || errno)
		return (ft_free(op, lemin_error(lemin, ERRD, op)));
	while (!ret && (ret = ft_getsln(lemin->input, &op, &lemin->map)))
		if (ret < 0)
			return (lemin_error(lemin, "%m\n"));
		else if (op && *op == '#' && *(op + 1) != '#' && !(ret = 0))
			continue ;
		else if ((ret = parsevertex(lemin, &op, graph)) && ret != NOP)
			return (ft_free(op, ret));
	return (ft_free(op, graph->len > 0 ? YEP : NOP));
}
