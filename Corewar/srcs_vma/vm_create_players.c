/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:30 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/18 18:39:04 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	player_instructions(char *buf, t_env *env)
{
	ft_memcpy(env->champions[env->nb_players].instructions, buf,
			env->champions[env->nb_players].header.prog_size);
	return (1);
}

int	player_header(char *buf, t_env *env)
{
	char			magic[4];
	char			prog_size[4];
	int				mod_padding;

	ft_memcpy(magic, buf, 4);
	check_magic(magic, env);
	ft_memcpy(env->champions[env->nb_players].header.prog_name,
		&buf[sizeof(((t_header*)0)->magic)], PROG_NAME_LENGTH);
	mod_padding = (sizeof(((t_header*)0)->prog_name) % 4) ?
		(4 - (sizeof(((t_header*)0)->prog_name) % 4)) : 0;
	ft_memcpy(prog_size, &buf[sizeof(((t_header*)0)->magic)
		+ sizeof(((t_header*)0)->prog_name) + mod_padding], 4);
	check_prog_size(prog_size, env);
	ft_memcpy(env->champions[env->nb_players].header.comment,
		&buf[sizeof(((t_header*)0)->magic) + sizeof(((t_header*)0)->prog_name)
		+ sizeof(((t_header*)0)->prog_size) + mod_padding], COMMENT_LENGTH);
	env->champions[env->nb_players].player_id = env->nb_players + 1;
	return (1);
}

int	create_player(char *file, t_env *env)
{
	int		fd;
	char	buf[sizeof(t_header)];
	int		ret;

	ft_bzero(buf, sizeof(t_header));
	ft_memcpy(env->champions[env->nb_players].file, file,
			(ft_strlen(file) > 50 ? 50 : ft_strlen(file)));
	if ((fd = open(file, O_RDONLY)) < 1 || read(fd, buf, 0) == -1)
		display_errors_with_value(0, 0, env);
	if ((ret = read(fd, buf, sizeof(t_header))) != sizeof(t_header))
	{
		ft_printf("File %s ", file);
		display_errors("is too small to be a champion");
	}
	player_header(buf, env);
	if ((ret = read(fd, buf, CHAMP_MAX_SIZE)) !=
			(int)env->champions[env->nb_players].header.prog_size)
		display_errors("Error prog_size != instructions size");
	player_instructions(buf, env);
	if ((ret = read(fd, buf, 1)))
		display_errors((ret < 0) ? "Read error" : "File too big");
	env->nb_players++;
	if ((ret = close(fd)) == -1)
		display_errors("Close error.");
	return (1);
}
