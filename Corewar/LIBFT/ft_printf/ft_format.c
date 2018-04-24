/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:28:03 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 14:45:57 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	g_formats[127];

void			ft_set_g_formats(void)
{
	g_formats['s'].printfunc = ft_is_s;
	g_formats['S'].printfunc = ft_is_cap_s;
	g_formats['p'].printfunc = ft_is_p;
	g_formats['d'].printfunc = ft_is_d;
	g_formats['D'].printfunc = ft_is_cap_d;
	g_formats['i'].printfunc = ft_is_i;
	g_formats['o'].printfunc = ft_is_o;
	g_formats['O'].printfunc = ft_is_cap_o;
	g_formats['u'].printfunc = ft_is_u;
	g_formats['U'].printfunc = ft_is_cap_u;
	g_formats['x'].printfunc = ft_is_x;
	g_formats['X'].printfunc = ft_is_cap_x;
	g_formats['c'].printfunc = ft_is_c;
	g_formats['C'].printfunc = ft_is_cap_c;
}

static int		ft_set_spec(t_params *arg, char spec, va_list lst, char **buf)
{
	char		*processed_string;

	processed_string = NULL;
	if (g_formats[(int)spec].printfunc)
	{
		ft_general_overrides(arg);
		processed_string = g_formats[(int)spec].printfunc(arg, lst);
		*buf = ft_strjoin_clr(*buf, processed_string, 2);
		return (1);
	}
	return (0);
}

static void		ft_is_not_perc(char **buf, char *format, int *index)
{
	int			i;
	char		*addition;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i += 1;
	addition = ft_strndup(format, i);
	*index += i - 1;
	*buf = ft_strjoin_clr(*buf, addition, 2);
}

static void		ft_is_perc(char **buf, char *format, int *index, va_list lst)
{
	int			i;
	t_params	arg;

	i = 1;
	ft_bzero(&arg, sizeof(t_params));
	*index += 1;
	while (format[i] != '\0')
	{
		if (ft_flwp(&arg, format, &i) == 1)
			;
		else if (ft_set_spec(&arg, format[i], lst, buf) == 1)
			break ;
		else
		{
			*buf = ft_strjoin_clr(*buf, ft_is_s_perc(&arg, format + i), 2);
			break ;
		}
		i++;
	}
	*index += i - 1;
	if (arg.flags[ERR])
		*index = -1;
}

int				ft_read_format(char *format, va_list lst, int fd)
{
	int			index;
	char		*buf;

	ft_set_g_formats();
	buf = NULL;
	index = 0;
	if (format)
	{
		while (format[index] != '\0')
		{
			if (format[index] == '%')
			{
				if (ft_strlen(format) == 1)
					return (0);
				ft_is_perc(&buf, format + index, &index, lst);
				if (index == -1)
					return (ft_print_buffer(buf, index, fd));
			}
			else
				ft_is_not_perc(&buf, format + index, &index);
			index++;
		}
	}
	return (ft_print_buffer(buf, index, fd));
}
