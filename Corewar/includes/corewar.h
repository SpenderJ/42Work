/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:53:01 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/21 14:56:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H
# define NB_INSTRUCTIONS 16
# define COLOR 8
# define UNDER_LINE 16
# define STAND_OUT 32
# include <ncurses.h>
# include "../libft/includes/libft.h"
# include "../includes/op.h"

typedef struct		s_op
{
	char	name[6];
	int		params_number;
	int		params[3];
	char	op_code;
	int		nb_cycles;
	char	description[37];
	int		modify_carry;
	int		direct_size;
}					t_op;

typedef struct		s_player
{
	int			player_id;
	char		file[50];
	t_header	header;
	char		instructions[CHAMP_MAX_SIZE];
	int			size;
	int			nb_lives;
}					t_player;

typedef struct		s_process
{
	unsigned long		id;
	int					reg[REG_NUMBER];
	int					col_pair;
	int					current;
	int					pc;
	char				opcode;
	int					ocp[3];
	int					cycle_before_exec;
	int					carry;
	int					alive;
	int					last;
	int					size;
	struct s_process	*prev;
	struct s_process	*next;
}					t_process;

typedef struct		s_stack
{
	t_process		*last_process;
	t_process		*first_process;
	t_process		*followed;
	unsigned long	nb_process;
	unsigned long	process_id;
}					t_stack;

typedef	struct		s_fork
{
	int	pc;
	int	col_pair;
	int	carry;
	int	alive;
	int	last;
}					t_fork;

typedef struct		s_option
{
	int	a;
	int	d;
	int	s;
	int	v;
	int	n;
	int	visu;
}					t_option;

typedef struct		s_env
{
	char			arena[MEM_SIZE];
	unsigned int	arena2[MEM_SIZE];
	int				cycle;
	int				attr_id[2][MAX_PLAYERS];
	int				cycle_to_die;
	int				nb_players;
	int				nb_live_env;
	int				cycle_sec;
	t_player		champions[MAX_PLAYERS];
	t_player		*last_alive;
	t_op			instructions[NB_INSTRUCTIONS];
	t_stack			process;
	t_option		option;
}					t_env;

typedef struct		s_param
{
	int		value[3];
	int		size[3];
	int		adress;
	int		length;
	int		success;
	char	param[2][4];
}					t_param;

/*
** vm_initialization.c
*/

int					check_constants(void);
int					init_options(t_env *env);
int					init_instructions(t_env *env);
int					init_vm_champions(t_env *env);
int					init_vm_environment(t_env *env);

/*
** vm_options.c
*/

int					search_options(t_env *env, char **argv, int argc, int i);
int					check_options(char **argv, int argc, t_env *env);
void				ft_sort_id_and_create_players(t_env *env, char **argv);

/*
** vm_create_players.c
*/

int					player_instructions(char *buf, t_env *env);
int					player_header(char *buf, t_env *env);
int					create_player(char *file, t_env *env);

/*
** vm_check_players.c
*/

int					check_magic(char *magic, t_env *env);
int					check_prog_size(char *prog_size, t_env *env);

/*
** vm_load_players.c
*/

int					load_players(t_env *env);

/*
** vm_create_process.c
*/

void				create_process(t_env *env, int *reg, int start_position,
					t_fork *fork);
int					init_process_stack(t_env *env);

/*
** vm_destroy_process.c
*/

void				free_memory(t_env *env, t_process *process, int d);
void				destroy_all(t_env *env, int d);
int					search_dead_process(t_env *env);

/*
** vm_exec_process.c
*/

int					exec_options(t_env *env, int cycle);
int					exec_process(t_env *env);
void				run_the_game(t_env *env, int cycle_consumed,
					int check, int delta);

/*
** vm_instructions_size.c
*/

int					params_size_ocp(t_env *env, t_process *process,
					t_param *param);
int					size_param(t_env *env, t_process *process);
int					check_ocp(t_env *env, t_process *process);
int					size_instruction(t_env *env, t_process *process);

/*
** vm_exec_instructions.c
*/

int					nb_cycles_instruction(t_env *env, t_process *process);
int					new_instruction(t_env *env, t_process *process);
int					exec_instruction(t_env *env, t_process *process);

/*
** vm_exec_functions.c
*/

int					check_adress(int adress);
int					register_value(t_process *process, int reg_number);
int					indirect_value(t_env *env, int start);

/*
** vm_exec_functions_2.c
*/

int					copy_register(t_process *process, char *buf,
					int reg_number);
void				copy_memory_area(t_env *env, char *buf, int start,
					int size);
void				modify_register_content(t_process *process, char *new_value,
					int reg_number);
void				modify_memory_content(t_env *env, char *buf, t_param *param,
					t_process *process);

/*
** vm_display_arena.c
*/

int					display_memory_area(char byte);
int					display_specific_area(t_env *env, int start, int end);
int					display_arena(t_env *env);

/*
** vm_visu.c
*/

void				ft_init_visu(t_env *env);
void				init_arena(t_env *env);
int					display_ncurses(t_env *env, t_process *process, int start,
					int size);
void				display_info_ncurses(t_env *env, t_process *process);
void				ft_display(t_env *env);
void				ft_print_info(t_env *env);

/*
** vm_display_messages.c
*/

void				display_usage(char **argv);
int					display_end(t_env *env);
int					display_start(t_env *env);

/*
** vm_display_options.c
*/

int					show_details(t_env *env, t_process *process,
					t_param *param);
int					show_operations(t_env *env, t_process *process,
					t_param *param);
int					show_deaths(t_env *env, t_process *process);
int					show_pc_movements(t_env *env, t_process *process);

/*
** vm_display_errors.c
*/

void				display_errors_with_value(int value, int code, t_env *env);
void				display_errors(char *error_message);

/*
** vm_debug.c
*/

int					display_process(t_env *env);
int					display_champions(t_env *env);
int					display_instructions(t_env *env);
int					debug(t_env *env);

/*
** exec
*/

int					exec_live(t_env *env, t_process *process);
int					exec_ld(t_env *env, t_process *process);
int					exec_lld(t_env *env, t_process *process);
int					exec_ldi(t_env *env, t_process *process);
int					exec_lldi(t_env *env, t_process *process);
int					exec_st(t_env *env, t_process *process);
int					exec_and(t_env *env, t_process *process);
int					exec_zjmp(t_env *env, t_process *process);
int					exec_sti(t_env *env, t_process *process);
int					exec_fork(t_env *env, t_process *process);
int					exec_lfork(t_env *env, t_process *process);
int					exec_aff(t_env *env, t_process *process);
int					exec_add(t_env *env, t_process *process);
int					exec_sub(t_env *env, t_process *process);
int					exec_or(t_env *env, t_process *process);
int					exec_xor(t_env *env, t_process *process);

/*
** ============================================================================
*/

/*
** ASM FILES
*/

typedef struct		s_slist
{
	char			*str;
	struct s_list	*first;
	struct s_list	*next;
}					t_tlist;

typedef struct		s_asm
{
	int				a;
	int				b;
	int				h;
	int				ac;
	int				first;
	char			**av;
	char			**file;
	char			**tab_label;
	char			bool_name;
	char			bool_comment;
	char			bool_header;
	char			*file_s_name;
	char			*ins;
	unsigned int	size;
	char			*path;
	int				fd_cor;
	t_list			*list;
	t_header		header;
}					t_asm;

typedef struct		s_ins
{
	unsigned short	tmp;
	unsigned int	tp;
	int				i;
	unsigned char	inst;
}					t_ins;

void				ft_error_strukt(t_asm *strukt);
char				**ft_malloc_tabtab(char **tab, char *str);
void				ft_put(char *str, char c, char fd, char bool_free);
void				ft_write(t_asm *strukt, const void *tmp, size_t len);
void				ft_aff(t_asm *s_asm, char *s);
void				ft_zjmp(t_asm *s_asm, char *s, int line);
void				ft_fork(t_asm *s_asm, char *s, int line);
void				ft_live(t_asm *s_asm, char *s, int line);
void				ft_lfork(t_asm *s_asm, char *s, int line);
void				ft_st(t_asm *s_asm, char *s, char opcode, int line);
void				ft_sti(t_asm *s_asm, char *s, char opcode, int line);
void				ft_ld_lld(t_asm *s_asm, char *s, char opcode, int line);
void				ft_ldi_lldi(t_asm *s_asm, char *s, char opcode, int line);
void				ft_sub_add(t_asm *s_asm, char *s, char opcode);
void				ft_and_xor_or(t_asm*s_asm, char *s, char opcode, int line);
void				ft_error(size_t id_error, char *name);
int					ft_print_file(t_asm *strukt);
int					ft_free_all(t_asm *strukt);
t_asm				*ft_check_file_s(t_asm *struckt);
void				ft_open_check_and_get_file(t_asm *s_asm);
t_asm				*ft_create_file_cor(t_asm *s_asm);
void				ft_write_magic_number(t_asm *s_asm);
void				ft_write_name(t_asm *s_asm);
void				ft_write_prog_size(t_asm *s_asm);
void				ft_write_comment(t_asm *s_asm);
void				ft_check_asm(t_asm *s_asm, int index);
void				ft_write_instructions(t_asm *s_asm);
t_list				*ft_linked_list_str(t_list *list, char *str, char to_free);
unsigned int		ft_find_label(t_asm *strukt, char *s, int actual);
void				ft_op_dir(char *s, char *bool_op, char *bool_dir);
char				*ft_strjoin_set(char *s1, char *s2, char setting);
int					ft_find_line(t_asm *s_asm, char *s, int k, int line);
int					ft_count(char *s, char t_dir, int i);
void				ft_write_ui(unsigned int value, t_asm *s_asm);
void				ft_write_us(unsigned short value, t_asm *s_asm);
int					ft_find_instruction(char *s);
unsigned char		ft_write_codage(char *s);
void				ft_check_header(void);
void				ft_exit(char *str);
void				ft_exit_and_destroy(t_asm *s_asm, char *str);
void				ft_check_instruction_line(char *s, char nbr, char *inst);
char				ft_is_r(char *s, char *nbr, char *inst, int *index);
char				ft_is_ind(char *s, char *nbr, char *inst, int *index);
char				ft_is_label(char *s, char *nbr, char *inst, int *index);

#endif
