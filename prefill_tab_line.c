/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill_tab_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:44:27 by qperrin           #+#    #+#             */
/*   Updated: 2020/10/18 12:49:41 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	prefill_line_1(t_case *tab, int n)
{
	int i;
	int j;

	i = 1;
	while (i < n + 1)
	{
		if (get_case(tab, n, 0, i)->value == n)
		{
			j = 0;
			while (j != n)
			{
				get_case(tab, n, n - j, i)->value = n - j;
				get_case(tab, n, n - j, i)->hard_correct = 1;
				j++;
			}
		}
		i++;
	}
}

void	prefill_line_2(t_case *tab, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n + 1)
	{
		if (get_case(tab, n, 0, i)->value == 1)
		{
			get_case(tab, n, 1, i)->value = n;
			get_case(tab, n, 1, i)->hard_correct = 1;
			if (get_case(tab, n, n + 1, i)->value == n)
			{
				j = -1;
				while (++j != n)
				{
					get_case(tab, n, n - j, i)->value = n - j;
					get_case(tab, n, n - j, i)->hard_correct = 1;
				}
			}
		}
	}
}

void	prefill_line_3(t_case *tab, int n)
{
	int i;

	i = 0;
	while (i < n + 1)
	{
		if ((get_case(tab, n, 0, i)->value +
							get_case(tab, n, n + 1, i)->value) == n + 1)
		{
			get_case(tab, n, get_case(tab, n, 0, i)->value, i)->value = n;
			get_case(tab, n, get_case(tab, n, 0, i)->value,
							i)->hard_correct = 1;
		}
		if (get_case(tab, n, n + 1, i)->value == 1)
		{
			get_case(tab, n, n, i)->value = n;
			get_case(tab, n, n, i)->hard_correct = 1;
		}
		i++;
	}
}

void	prefill_line_4(t_case *tab, int n)
{
	int i;

	i = -1;
	while (++i < n + 1)
	{
		if ((get_case(tab, n, 0, i)->value +
							get_case(tab, n, n + 1, i)->value) == 3)
		{
			get_case(tab, n, 1, i)->hard_correct = 1;
			get_case(tab, n, n, i)->hard_correct = 1;
			if (get_case(tab, n, 0, i)->value == 1)
				get_case(tab, n, 1, i)->value = n;
			else
				get_case(tab, n, 1, i)->value = n - 1;
			if (get_case(tab, n, n + 1, i)->value == 1)
				get_case(tab, n, n, i)->value = n;
			else
				get_case(tab, n, n, i)->value = n - 1;
		}
	}
}

void	prefill_line(t_case *tab, int n)
{
	prefill_line_1(tab, n);
	prefill_line_2(tab, n);
	prefill_line_3(tab, n);
	prefill_line_4(tab, n);
}
