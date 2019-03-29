/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 04:09:52 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 05:09:18 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

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

int		hamming_distance(int **map, int mapSize) {
	int		distance = 0;

	if (issolvable(map, mapSize) == 0)
		printf("Non solvable\n");
	else
		printf("Solvable\n");
	return distance;
}
