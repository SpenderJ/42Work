/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:57 by juspende          #+#    #+#             */
/*   Updated: 2018/03/23 15:49:47 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#include "lemin.h"

static t_lemin	*g_lemin = NULL;
static t_map	*g_graph = NULL;

void			drawvertex(t_vertex *v)
{
	int color;

	if (v == g_lemin->start)
		color = COLOR_PAIR(2);
	else
		color = v == g_lemin->end ? COLOR_PAIR(6) : COLOR_PAIR(0);
	wmove(stdscr, (v->y * 3), (v->x * 5));
	wattr_on(stdscr, 0x200000, 0x0);
	wprintw(stdscr, "%d", v->occupied);
	wattr_off(stdscr, 0x200000, 0x0);
	wattr_on(stdscr, 0x242a00, 0);
	mvwaddch(stdscr, (v->y * 3) + 1, (v->x * 5) - 2, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) + 1, (v->x * 5) - 1, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) + 1, (v->x * 5), (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) + 1, (v->x * 5) + 1, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) + 1, (v->x * 5) + 2, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) - 1, (v->x * 5) - 2, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) - 1, (v->x * 5) - 1, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) - 1, (v->x * 5), (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) - 1, (v->x * 5) + 1, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3) - 1, (v->x * 5) + 2, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3), (v->x * 5) - 3, (chtype)(' ' | color));
	mvwaddch(stdscr, (v->y * 3), (v->x * 5) + 3, (chtype)(' ' | color));
	wattr_off(stdscr, 0x242a00, 0);
}

void			lemin_guidraw(void)
{
	size_t		it;

	if (!g_lemin || !(g_lemin->options & OPT_NGUI))
		return ;
	it = 0;
	while (it < g_graph->cap)
	{
		if (!(g_graph->bucks[it++] & BUCKET_BOTH))
			drawvertex((t_vertex *)g_graph->vals + it - 1);
	}
	wrefresh(stdscr);
	usleep(300000);
}

void			update(int sig)
{
	(void)sig;
	endwin();
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	init_color(COLOR_WHITE, 0x12c, 0x12c, 0x12c);
	init_pair(0x2a, 0x8, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	clear();
	refresh();
	lemin_guidraw();
}

void			lemin_guiexit(void)
{
	if (!g_lemin || !(g_lemin->options & OPT_NGUI))
		return ;
	usleep(3000000);
	endwin();
}

void			lemin_guiinit(t_lemin *lemin, t_map *graph)
{
	if (!(lemin->options & OPT_NGUI))
		return ;
	g_lemin = lemin;
	g_graph = graph;
	update(0);
	signal(SIGWINCH, update);
}
