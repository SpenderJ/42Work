/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:00:47 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 12:00:48 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../LIBFT/libft.h"

# define RED	"\x1b[31m"
# define GRN	"\x1b[32m"
# define YEL	"\x1b[33m"
# define BLU	"\x1b[34m"
# define MAG	"\x1b[35m"
# define CYA	"\x1b[36m"
# define RES	"\x1b[0m"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define REG_NUMBER				16
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define IDX_MOD				(MEM_SIZE / 8)

# define COREWAR_EXEC_MAGIC		0xea83f3
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH];
}					t_header;

typedef struct		s_list
{
	char			*str;
	struct s_list	*first;
	struct s_list	*next;
}					t_list;

typedef struct		s_instruction
{
	unsigned short	tmp;
	unsigned int	tp;
	int				i;
	unsigned char	inst;
}					t_instruction;

typedef struct		s_asm
{
	int				first;
	int				a;
	int				h;
	char			*b;
	int				ac;
	char			**av;
	char			**file;
	char			**tab_label;
	char			*file_s_name;
	unsigned int	size;
	char			*path;
	char			*ins;
	t_header		header;
	char			bool_name;
	char			bool_comment;
	char			bool_header;
	int				fd_cor;
	t_list			*list;
	char			*instruction;
}					t_asm;

void				ft_error(size_t id_error, char *name);
void				ft_exit(char *str);
t_asm				*ft_create_file_cor(t_asm *strukt);
void				ft_check_header(void);
void				ft_exit_and_destroy(t_asm *strukt, char *str);
void				ft_op_dir(t_asm *strukt, char *s, char *bool_op,
	char *bool_dir);
void				ft_print_file(char **tab_file);
void				ft_write(t_asm *strukt, const void *tmp, size_t len);
int					ft_count(t_asm *strukt, char *s, char t_dir, int i);
char				*ft_strjoin_set(char *s1, char *s2, char setting);
void				ft_write_us(unsigned short value, t_asm *strukt);
void				ft_write_ui(unsigned int value, t_asm *strukt);

static t_asm		*ft_check_comments(t_asm *strukt, char *str, int ind,
	int len);
static t_asm		*ft_check_nme(t_asm *strukt, char *str, int ind,
	int len);
static char			ft_check_useless_line(char *str);
void				ft_check_instruction_line(char *s, char nbr, char *inst);
t_asm				*ft_check_file_s(t_asm *strukt);
void				ft_check_asm(t_asm *strukt, int index);

unsigned int		ft_find_label(t_asm *strukt, char *s, int first,
	int actual);
static t_asm		*ft_ins(t_asm *strukt);
int					ft_find_line(t_asm *strukt, char *s, int k, int line);
int					ft_find_instruction(char *s);
void				ft_write_magic_number(t_asm *strukt);
void				ft_write_prog_size(t_asm *strukt);
void				ft_write_comment(t_asm *strukt);
void				ft_write_name(t_asm *strukt);
unsigned char		ft_write_codage(char *s, t_asm *strukt);

void				ft_write_instructions(t_asm *strukt);

void				ft_live(t_asm *strukt, char *s, int line);
void				ft_st(t_asm *strukt, char *s, char opcode, int line);
void				ft_sti(t_asm *strukt, char *s, char opcode, int line);
void				ft_and_xor_or(t_asm *strukt, char *s, char opcode,
	int line);
void				ft_ldi_lldi(t_asm *strukt, char *s, char opcode,
	int line);
void				ft_aff(t_asm *strukt, char *s);
void				ft_ld_lld(t_asm *strukt, char *s, char opcode, int line);
void				ft_sub_add(t_asm *strukt, char *s, char opcode);
void				ft_zjmp(t_asm *strukt, char *s, int line);
void				ft_fork(t_asm *strukt, char *s, int line);
void				ft_lfork(t_asm *strukt, char *s, int line);

char				ft_is_r(char *s, char *nbr, char *inst, int *index);
char				ft_is_ind(char *s, char *nbr, char *inst, int *index);
char				ft_is_label(char *s, char *nbr, char *inst, int *index);

#endif
