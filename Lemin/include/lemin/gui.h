/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin/gui.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:51:54 by juspende          #+#    #+#             */
/*   Updated: 2018/03/21 15:11:47 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_GUI_H
# define LEMIN_GUI_H

# include "lemin.h"

extern void	lemin_guiinit(t_lemin *lemin, t_map *graph);
extern void	lemin_guiexit(void);
extern void	lemin_guidraw(void);

#endif
