/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:45:30 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:06:39 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "strutils.h"
#include "errorhandling.h"

void	ft_prt_line(t_case *tab, int n, int x, int y)
{
	while (x <= n + 1)
	{
		if (get_case(tab, n, x, y)->value != 0)
			ft_putnbr_lite(get_case(tab, n, x, y)->value);
		else
			write(1, " ", 1);
		if (x != n + 1)
			write(1, " ", 1);
		if (x == 0 || x == n)
			write(1, "| ", 2);
		++x;
	}
}

void	display_tab_pretty(t_case *tab, int n, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	write(1, FT_COLOR_GRN, color * 6);
	while (y <= n + 1)
	{
		x = 0;
		ft_prt_line(tab, n, x, y);
		++y;
		write(1, "\n", 1);
		if (y == 1 || y == n + 1)
		{
			write(1, "------------------------------", (n + 2) * 2 + 3);
			write(1, "\n", 1);
		}
	}
	write(1, FT_COLOR_NRM, color * 5);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
