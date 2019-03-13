/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:53:27 by juspende          #+#    #+#             */
/*   Updated: 2018/10/28 17:23:05 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int					ft_handle_param(char *param, int *errors_count, int *check, t_flags *params)
{
	int				num;

	num = 0;
	if (param[0] == '-' && param[1] && *check_for_flags)
		ft_strcmp(param, "--") == 0 && ++params->options_count ? *check_for_flags = 0 : ft_set_options(param, params);
	else if (ft_is_file_or_dir(param))
	{
		ft_put_in_options(param, ft_is_file(param) ? &(params->files) : &(params->folders));
		*check_for_flags = 0;
		files_count++;
	}
	else if (ft_strlen(param) == 0)
		ft_throw_error_fts_open();
	else if (++(*errors_count))
		ft_put_in_options(param, &(params->not_founds));
	return (files_count);
}

static t_flags		ft_getparam(int argc, char **argv)
{
	int				c;
	t_flags			ls_param;
	int				check;
	int				files_count;
	int				error_count;

	ft_memset(&ls_param, 0, sizeof(ls_param));
	c = 0;
	check = 1;
	files_count = 0;
	error_count = 0;

	while (++c < argc)
		files_count += ft_handle_param(argv[c], &error_count, &check,
				&ls_param);
	if (error_count > 0)
		ft_error(ls_param.not_founds, &ls_param);
	ls_param.display_dirs = argc - ls_param.options_count > 2;
	if (files_count == 0 && error_count == 0)
		ft_add_default_folder(&ls_param);
	ft_sort_params(&ls_param);
	return (ls_param);
}

int					main(int argc, char **argv)
{
	t_flags		ls_flags;

	ls_flags = ft_getparam(argc, argv);
	return (0);
}
