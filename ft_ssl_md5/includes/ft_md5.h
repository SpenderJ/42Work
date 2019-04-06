/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:38:32 by juspende          #+#    #+#             */
/*   Updated: 2019/04/05 19:06:19 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H

# define FT_MD5_H

# include "ft_ssl.h"

# define F1(X, Y, Z) (Z ^ (X & (Y ^ Z)))
# define F2(X, Y, Z) F1(Z, X, Y)
# define F3(X, Y, Z) (X ^ Y ^ Z)
# define F4(X, Y, Z) (Y ^ (X | ~Z))
# define MD5STEP(F, W, X, Y, Z, DATA, S) \
	( W += F(X, Y, Z) + DATA,  W = W<<S | W>>(32-S),  W += X )

typedef struct		s_md5
{
	unsigned long	buf[4];
	unsigned long	bits[2];
	unsigned char	in[64];
}					t_md5;

void			ft_md5Transform(unsigned long buf[4], unsigned long const in[16]);

#endif
