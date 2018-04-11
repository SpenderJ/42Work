/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:27:16 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/11 15:28:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../includes/op.h"

void		ft_bzero(void *s, size_t n);
void		ft_put(char *str, char c, char fd, char bool_free);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *src);
int			get_next_line(int const fd, char **line);
char		**ft_malloc_tabtab(char **tab, char *str);
void		ft_strdel(char **as);
size_t		ft_strlen(const char *str);
char		*ft_strndup(const char *s, size_t n);
void		ft_memdel(void **ap);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_memdel(void **ap);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
char		*ft_itoa_base(int value, int base);
char		**ft_strsplit(char *str);

#endif
