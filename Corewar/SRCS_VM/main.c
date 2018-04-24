/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:09:37 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/14 14:09:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    print_usage()
{
    ft_dprintf(2, "Usage: ./corewar [-dump N || -v] \
[-n N] <champion1.cor> <...>\n");

}

static t_gen   *init_params(t_gen *params, char **av, int n_arg)
{
    int         fd;
    char        *file;

    if (!(params = (t_gen *)malloc(sizeof(t_gen))))
        return (NULL);
    // params->nb_players = n_arg - 1;
    params->nb_players = 0;
    params->dump = 0;
    if (n_arg >= 1 && ft_strcmp("-dump", av[1]) == 0)
    {
        if (!(is_valid_dump(params, n_arg, av)))
            return (NULL);
        av += 2;
        n_arg -= 2;
    }
    if (!(params->players = init_players(params, av, n_arg)))
        return (NULL);
    return (params);
}

int     main(int ac, char **av)
{
    t_gen   *params;

    // if (ac <= 1)
        // print_usage();
    // else if (ac > 5)
        // ft_put("Too many champions", '\n', 2, 0);
    // else if ((params = init_params(params, av, ac)) == NULL)
        // ft_put("Can't read source file", '\n', 2, 0);
    // else
        // print_params(params);
    if ((params = init_params(params, av, ac - 1)))
        print_params(params);
    else
        print_usage();
    free(params);
    return (0);
}
