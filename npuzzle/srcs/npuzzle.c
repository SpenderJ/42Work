/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:15:36 by juspende          #+#    #+#             */
/*   Updated: 2019/03/13 15:44:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

int			main(int argc, char **argv) {
	int		**map;

	if (!argc || ! argv || argc != 2 || !argv[1])
		return (handle_error(NO_FILE_INPUT));
	if ((map = npuzzle_parse(argv[1])) == NULL)
		return (handle_error(ILLEGAL_MAP));
	return (0);
}
