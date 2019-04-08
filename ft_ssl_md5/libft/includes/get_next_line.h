/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:26:39 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:26:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 8

typedef struct	s_buf
{
	char			buf[BUFF_SIZE];
	int				fd;
	int				nb;
	int				line_len;
	struct s_buf	*next;
}				t_buf;

int				get_next_line(const int fd, char **line);

#endif
