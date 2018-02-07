/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:19:24 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 13:19:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

typedef struct	s_line
{
	char			*str;
	struct s_line	*next;
}				t_line;

typedef struct	s_lines
{
	t_line *first;
	t_line *last;
}				t_lines;

#endif
