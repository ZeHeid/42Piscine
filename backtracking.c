/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:08:42 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 15:10:08 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	checkpos_row_for(t_case *tab, int n, int y)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = 1;
	while (i <= n)
	{
		if (max < get_case(tab, n, i, y)->value)
		{
			count++;
			max = get_case(tab, n, i, y)->value;
		}
		i++;
	}
	if (count <= get_case(tab, n, 0, y)->value)
		return (1);
	return (0);
}

int	checkpos_row_back(t_case *tab, int n, int y)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = n;
	while (i >= 1)
	{
		if (max < get_case(tab, n, i, y)->value)
		{
			count++;
			max = get_case(tab, n, i, y)->value;
		}
		i--;
	}
	if(count <= get_case(tab, n, n + 1, y)->value ||  max <= n - 2)	
		return (1);
	return (0);
}

int	checkpos_clmn_for(t_case *tab, int n, int x)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = 1;
	while (i <= n)
	{
		if (max < get_case(tab, n, x, i)->value)
		{
			count++;
			max = get_case(tab, n, x, i)->value;
		}
		i++;
	}
	if (count <= get_case(tab, n, x, 0)->value)
		return (1);
	return (0);
}

int	checkpos_clmn_back(t_case *tab, int n, int x)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = n;
	while (i >= 1)
	{
		if (max <  get_case(tab, n, x, i)->value)
		{
			count++;
			max = get_case(tab, n, x, i)->value;
		}
		i--;
	}
	if (count <= get_case(tab, n, x, n + 1)->value || max <= n - 2)
		return (1);
	return (0);
}

int	no_identicalpos(t_case *tab, int n, int x, int y)
{
	int i;
	int data;

	data = get_case(tab, n, x, y)->value;
	i = 1;
	while (i <= n)
	{
		if (get_case(tab, n, i, y)->value == data && x != i)
			return (0);
		if (get_case(tab, n, x, i)->value == data && y != i)
			return (0);
		i++;
	}
	return (1);
}
