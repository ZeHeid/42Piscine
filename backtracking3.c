/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:23:03 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 14:33:58 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	checkpos_row_forlast(t_case *tab, int n)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = 1;
	while (i <= n)
	{
		if (max < get_case(tab, n, i, n)->value)
		{
			count++;
			max = get_case(tab, n, i, n)->value;
		}
		i++;
	}
	if (count == get_case(tab, n, 0, n)->value)
		return (1);
	return (0);
}

int	checkpos_row_backlast(t_case *tab, int n)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = n;
	while (i >= 1)
	{
		if (max < get_case(tab, n, i, n)->value)
		{
			count++;
			max = get_case(tab, n, i, n)->value;
		}
		i--;
	}
	if(count == get_case(tab, n, n + 1, n)->value)
		return (1);
	return (0);
}

int	checkpos_clmn_forlast(t_case *tab, int n)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = 1;
	while (i <= n)
	{
		if (max < get_case(tab, n, n, i)->value)
		{
			count++;
			max = get_case(tab, n, n, i)->value;
		}
		i++;
	}
	if (count == get_case(tab, n, n, 0)->value)
		return (1);
	return (0);
}

int	checkpos_clmn_backlast(t_case *tab, int n)
{
	int i;
	int count;
	int max;

	max = 0;
	count = 0;
	i = n;
	while (i >= 1)
	{
		if (max < get_case(tab, n, n, i)->value)
		{
			count++;
			max = get_case(tab, n, n, i)->value;
		}
		i--;
	}
	if (count == get_case(tab, n, n, n + 1)->value)
		return (1);
	return (0);
}
