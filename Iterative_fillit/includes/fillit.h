/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:38:44 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/17 10:34:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUF_SIZE 21

#include <stdio.h>

typedef struct		t_solution
{
	char	**so;
	int		tetriminos;
	int		map_si;
}					t_solution;

typedef struct		s_bloc
{
	struct s_bloc	*next;
	char			**data;
}					t_bloc;

int				best_map(char *str, char ***tab, t_solution *solution);
int				empty_col(char **tab, int index);
char			***clear_tabs(char ***tab);
int				empty_line(char *str);
char			**ft_clear_empty_line(char **tab, int size);
int				ft_list_foreach(t_bloc *begin_list, int(*f)(char **));
void			ft_list_push_back(t_bloc **begin_list, char **data);
t_bloc			*ft_create_elem(char **data);
int				verification(t_bloc *bloc);
char			***lst_to_tab(t_bloc *tab);
int				ft_list_size (t_bloc *begin_list);
void			make_letters(char **tab, char c);
void			get_my_letters(char ***tab);
char			**ft_clear_empty_column(char **tab, int size);
void			resolve(char ***, int, t_solution *solution);
void			fill_map(char **map, int map_size);
void			free_tab(char **tab);
int				success(char **map, int tetriminos_number);
int				add_tetriminos(char **map, char **tetriminos, int map_size);
int				already_exist(char **tetriminos, char **map);
void			go_check(char *previous, char **map, char ***tetriminos);
int				letter_to_int(char c);
int				regen_map(char *previous, char **map, char ***tetriminos);
int				go_forward(char **map, char *previous, int nb);
int				previous_check(char *previous, int tetriminos_number);
int				str_check(char *str, char c);
int				rot(char *mot, int n, int k);
char			*generator(char *s, char ***tab, char **map, t_solution *solution);

#endif
