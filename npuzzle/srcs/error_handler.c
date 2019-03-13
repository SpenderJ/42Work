/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:59:06 by juspende          #+#    #+#             */
/*   Updated: 2019/03/13 16:21:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function returning an error and printing an error message on the error
 * output
*/

int			handle_error(char *descriptor) {
	write(2, descriptor, ft_strlen(descriptor));
	return (-1);
}
