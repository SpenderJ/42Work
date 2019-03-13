/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:58:30 by juspende          #+#    #+#             */
/*   Updated: 2018/09/22 15:19:07 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../printf/include/ft_printf.h"

typedef struct		s_flags
{
	int				hidden_files;
	int				reccursive;
	int				long_format;
	int				sort_bytime;
	int				sort_reverse;
	int				no_columns;
	int				colors;
	int				options_count;
	int				display_dirs;
	int				status;
	char			*current_path;
	char			**folders;
	char			**files;
	char			**not_founds;
}					t_flags;

/*
 ** FUNCTION DECLARATION
*/

int				main(int argc, char **argv);
static t_flags	ft_getparam(int argc, char **argv);

#endif
