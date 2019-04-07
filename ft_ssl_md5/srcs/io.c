/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:50:41 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 15:05:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static char	*join_str(char *s1, char *s2)
{
	int		i;
	char	*final;
	int		sum;
	int		z;

	sum = 0;
	i = -1;
	if (s1)
		sum = ft_strlen(s1);
	if (s2)
		sum += ft_strlen(s2);
	if (sum > 0)
		final = malloc(sizeof(char) * sum + 1);
	else
		return (NULL);
	final[0] = '\0';
	if (s1)
		while (s1[++i] != '\0')
			final[i] = s1[i];
	z = -1;
	if (s2)
		while (s2[++z] != '\0')
			final[i++] = s2[z];
	final[i] = '\0';
	return (final);
}

static int	file_str(int fd, char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*final;
	int		ret;

	tmp = NULL;
	final = NULL;
	ret = 1;
	if ((tmp2 = malloc(sizeof(char) * 2)) == NULL)
		return (0);
	tmp2[0] = 0;
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		final = join_str(tmp2, tmp);
		free (tmp);
		free (tmp2);
		tmp2 = ft_strdup(final);
	}
	*str = ft_strdup(final);
	free (tmp2);
	free (final);
	return (TRUE);
}

int			io(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	int		fd;
	int		index;
	int		i;

	fd = 0;
	index = 0;
	i = -1;
	if ((ssl->to_hash = malloc(sizeof(char *) * (MAX_FILES + 1))) == NULL)
		return (EXIT_HELP);
	if ((ssl_flag->p || ssl->filenames[0] == NULL) && !isatty(fd)
			&& file_str(fd, &ssl->to_hash[index]) > 0 && ++ssl->size_printed)
		++index;
	ssl->c_stdin = index;
	while (ssl->filenames[++i] != NULL && ++ssl->size_printed)
	{
		if (ssl_flag->s && i == 0)
			ssl->to_hash[index++] = ft_strdup(ssl->filenames[i]);
		else if ((fd = open(ssl->filenames[i], O_RDONLY)) < 0)
			ssl->to_hash[index++] = NULL;
		else
			file_str(fd, &ssl->to_hash[index++]);
	}
	ssl->to_hash[index] = NULL;
	return (0);
}
