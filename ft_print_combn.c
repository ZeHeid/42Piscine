/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:59:21 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/15 12:07:50 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_table_n(int *tab, int n)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	print_recursive_tab(int *tab, int i, int n)
{
	if (i == 0)
		tab[i] = 0;
	else
		tab[i] = tab[i - 1] + 1;
	while (tab[i] <= 10 - n + i)
	{
		if (i == n - 1)
			ft_print_table_n(tab, n);
		else
			print_recursive_tab(tab, i + 1, n);
		tab[i]++;
	}
}

void	ft_print_combn(int n)
{
	int tab[n];

	print_recursive_tab(tab, 0, n);
}
