/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:53:34 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:13:10 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "rush.h"
#include "errorhandling.h"
#include "strutils.h"
#include "backtracking.h"
#include "backtracking2.h"

_Bool	set_flags(char *arg, int *pretty, int *color)
{
	*pretty = 0;
	*color = 0;
	if (ft_strcmp(arg, "--pretty-color") == 0)
	{
		*pretty = 1;
		*color = 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--pretty") == 0)
	{
		*pretty = 1;
		return (1);
	}
	return (0);
}

void	rush(int *clues, t_case *tab, int n, int *flags)
{
	tab = new_s_case(n / 4);
	fill_border(tab, n / 4, clues);
	prefill_col(tab, n / 4);
	prefill_line(tab, n / 4);
	display_tab_pretty(tab, n / 4, flags[1]);
	if (fill_recursive(tab, n / 4, 1, 1))
		if (flags[0])
			display_tab_pretty(tab, n / 4, flags[1]);
		else
			display_tab(tab, n / 4);
	else
		put_error(flags[1]);
}

int		set_flags_if_argc_3(int argc, char **argv, int *flags)
{
	if (argc == 3)
		if (!set_flags(argv[2], &flags[0], &flags[1]))
		{
			put_error(flags[1]);
			return (0);
		}
	return (1);
}

int		main(int argc, char **argv)
{
	t_case			*tab;
	int				n;
	int				*clues;
	int				flags[2];

	set_zero(&flags[0], &flags[1]);
	tab = NULL;
	if (set_flags_if_argc_3(argc, argv, flags) == 0)
		return (0);
	if (argc == 2 || argc == 3)
	{
		clues = ft_split_args(argv[1], &n);
		if (check_args(clues, n) && (n / 4) >= 4)
		{
			rush(clues, tab, n, flags);
			free(tab);
		}
		else
			put_error(flags[1]);
	}
	else
		put_error(flags[1]);
	return (0);
}
