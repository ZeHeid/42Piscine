/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill_tab_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:44:27 by qperrin           #+#    #+#             */
/*   Updated: 2020/10/18 12:46:43 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	prefill_col_1(t_case *tab, int n)
{
	int i;
	int j;

	i = 1;
	while (i < n + 1)
	{
		if (get_case(tab, n, i, 0)->value == n)
		{
			j = 0;
			while (j != n)
			{
				get_case(tab, n, i, n - j)->value = n - j;
				get_case(tab, n, i, n - j)->hard_correct = 1;
				j++;
			}
		}
		i++;
	}
}

void	prefill_col_2(t_case *tab, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n + 1)
	{
		if (get_case(tab, n, i, 0)->value == 1)
		{
			get_case(tab, n, i, 1)->value = n;
			get_case(tab, n, i, 1)->hard_correct = 1;
			if (get_case(tab, n, i, n + 1)->value == n)
			{
				j = 0;
				while (j != n)
				{
					get_case(tab, n, i, n - j)->value = j + 1;
					get_case(tab, n, i, n - j)->hard_correct = 1;
					j++;
				}
			}
		}
		i++;
	}
}

void	prefill_col_3(t_case *tab, int n)
{
	int i;

	i = 0;
	while (i < n + 1)
	{
		if ((get_case(tab, n, i, 0)->value +
							get_case(tab, n, i, n + 1)->value) == n + 1)
		{
			get_case(tab, n, i, get_case(tab, n, i, 0)->value)->value = n;
			get_case(tab, n, i,
							get_case(tab, n, i, 0)->value)->hard_correct = 1;
		}
		if (get_case(tab, n, n + 1, i)->value == 1)
		{
			get_case(tab, n, n, i)->value = n;
			get_case(tab, n, n, i)->hard_correct = 1;
		}
		i++;
	}
}

void	prefill_col_4(t_case *tab, int n)
{
	int i;

	i = -1;
	while (++i < n + 1)
	{
		if ((get_case(tab, n, i, 0)->value +
							get_case(tab, n, i, n + 1)->value) == 3)
		{
			get_case(tab, n, i, 1)->hard_correct = 1;
			get_case(tab, n, i, n)->hard_correct = 1;
			if (get_case(tab, n, i, 0)->value == 1)
				get_case(tab, n, i, 1)->value = n;
			else
				get_case(tab, n, i, 1)->value = n - 1;
			if (get_case(tab, n, i, n + 1)->value == 1)
				get_case(tab, n, i, n)->value = n;
			else
				get_case(tab, n, i, n)->value = n - 1;
		}
	}
}

void	prefill_col(t_case *tab, int n)
{
	prefill_col_1(tab, n);
	prefill_col_2(tab, n);
	prefill_col_3(tab, n);
	prefill_col_4(tab, n);
}
