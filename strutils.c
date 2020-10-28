/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:22:05 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 13:45:47 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "strutils.h"
#include "errorhandling.h"

int		*ft_split_args(char *arg, int *n)
{
	int				*ret;
	int				i;
	int				len;
	int				num;
	int				mi;

	if ((len = ft_strlen(arg)) == 0)
		return (NULL);
	if ((ret = malloc(len * sizeof(int))) == 0)
		return (NULL);
	set_zero(&i, &mi);
	while (i < len)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (ft_err(ret));
		num = 0;
		while (arg[i] >= '0' && arg[i] <= '9')
			num = num * 10 + arg[i++] - '0';
		ret[mi++] = num;
		if ((arg[i] != ' ' || i == len - 1) && arg[i])
			return (ft_err(ret));
		++i;
	}
	*n = mi;
	return (ret);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		++i;
	return (i);
}

void	set_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	ft_putnbr_lite(int nb)
{
	char c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_lite(nb / 10);
		ft_putnbr_lite(nb % 10);
	}
}

void	display_tab(t_case *tab, int n)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (y <= n)
	{
		x = 1;
		while (x <= n)
		{
			ft_putnbr_lite(get_case(tab, n, x, y)->value);
			if (x != n)
				write(1, " ", 1);
			++x;
		}
		++y;
		write(1, "\n", 1);
	}
}
