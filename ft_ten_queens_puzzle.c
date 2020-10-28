/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:37:09 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/14 21:58:43 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_table(int *tab)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		position_dame_correct(int *tab, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (tab[i] == tab[x] || x - i == tab[i] - tab[x]
				|| i - x == tab[i] - tab[x])
			return (0);
		i++;
	}
	return (1);
}

int		placement_dame(int *tab, int x, int y)
{
	int res;

	res = 0;
	while (y <= 9)
	{
		tab[x] = y;
		if (position_dame_correct(tab, x) == 1)
		{
			if (x == 9)
			{
				ft_print_table(tab);
				return (1);
			}
			else
				res = res + placement_dame(tab, x + 1, 0);
		}
		y++;
	}
	return (res);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];

	return (placement_dame(tab, 0, 0));
}
