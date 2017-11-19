#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_tetris
{
	char		**pos;
	int			l;
	int			h;
	char		value;
}				t_tetris;

int				main(int argc, char **argv);
t_list			*read_tetris(int fd);
void			print_map(t_map *map);
void			free_map(t_map *map);
t_map			*map_new(int size);
int				place(t_tetris *tetris, t_map *map, int x, int y);
void			set_piece(t_tetris *tetris, t_map *map, t_point *point, char c);
t_map			*solve(t_list *list);
t_point			*point_new(int x, int y);
t_tetris		*tetris_new(char **pos, int l, int h, char c);
void			free_tetris(t_tetris *tetris);
t_list			*free_list(t_list *list);
int				error(void);
int				test_file(char *str);
int				test_co(char *str, int c);
int				line(char *str, int c, int tet, int l);
t_list			*tetris_read(char *str);

#endif
