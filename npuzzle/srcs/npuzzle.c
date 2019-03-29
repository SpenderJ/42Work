/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:15:36 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 07:47:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function to calculte if a puzzle is solvable or no 
*/

static int issolvable(int **map, int size) {
	int i,j,k,cab=0,parity=0,perm[MAX*MAX],len;

	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(map[i][j] == 0)
				cab=size+size-i-j-2;
	for(j=k=0;j<size;j++)
		for(i=0;i<size;i++)
			perm[k++]=map[i][j];
	for(i=0;i<((size*size)-1);i++)
		if(perm[i]>-1 && perm[i]!=i) {
			for(k=i,len=-1,j=perm[k],perm[k]=-1,k=j;j>-1;j=perm[k],perm[k]=-1,k=j,len++);
			parity+=len;
		}
	return (cab+parity+1)&1;
}

/*
 * In case of error the program is returning -1, otherwise, it will return
 * 0 in case of good work
*/

int			main(int argc, char **argv) {
	int		**map;
	int		size;

	if (!argc || ! argv || argc != 2 || !argv[1])
		return (handle_error(NO_FILE_INPUT));
	if ((map = npuzzle_parse(argv[1], &size)) == NULL)
		return (handle_error(ILLEGAL_MAP));
	if (size > MAX)
		return (handle_error(TOO_BIG));
	(void)issolvable(map, size);
//	if (!issolvable(map, size))
//		return (handle_error(NOT_SOLVABLE));
	if (hamming_distance(map, size) < -1)
		return (handle_error(ERROR_RESOLVING));
	return (0);
}
