/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:50:41 by juspende          #+#    #+#             */
/*   Updated: 2019/04/14 15:34:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int	file_str(int fd, char **str, uint32_t *f_size)
{
	int			rd;
	char		*buf;
	char		*cpy;

	if (fd < 0)
		return (0);
	rd = 0;
	*f_size = 0;
	*str = ft_memalloc(1);
	buf = malloc(BUFSIZE + 1);
	cpy = NULL;
	while ((rd = read(fd, buf, BUFSIZE)) > 0)
	{
		cpy = malloc(sizeof(char) * (*f_size + rd + 1));
		ft_memcpy(cpy, *str, *f_size);
		ft_memcpy(cpy + *f_size, buf, rd);
		cpy[*f_size + rd] = '\0';
		*f_size += rd;
		free(*str);
		*str = cpy;
	}
	free(buf);
	(!f_size) && (**str = '\0');
	return (1);
}

int			io(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	int		fd;
	int		index;
	int		i;

	index = 0;
	if ((ssl->to_hash = malloc(sizeof(char *) * (MAX_FILES + 1))) == NULL)
		return (EXIT_HELP);
	if ((i = -1) && (ssl_flag->p || ssl->filenames[0] == NULL) && !isatty(0)
			&& file_str(0, &ssl->to_hash[index], &ssl->f_size[index]) > 0
			&& ++ssl->size_printed)
		++index;
	ssl->c_stdin = index;
	while (ssl->filenames[++i] != NULL && ++ssl->size_printed)
	{
		if (ssl_flag->s && i == 0 && (ssl->f_size[index] =
					ft_strlen(ssl->filenames[i])))
			ssl->to_hash[index] = ft_strdup(ssl->filenames[i]);
		else if ((fd = open(ssl->filenames[i], O_RDONLY)) < 0)
			ssl->to_hash[index] = NULL;
		else
			file_str(fd, &ssl->to_hash[index], &ssl->f_size[index]);
		++index;
	}
	ssl->to_hash[index] = NULL;
	return (0);
}
