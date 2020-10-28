/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:19:38 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 15:10:24 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "strutils.h"
#include "backtracking2.h"
#include "backtracking.h"
#include "backtracking3.h"


int	good_positionning(t_case *tab, int n, int x, int y)
{
	if (x == n && y == n)
	{
		printf("d");
		if (no_identicalpos(tab, n, x, y) == 1
				&& checkpos_clmn_backlast(tab, n) == 1
				&& checkpos_clmn_forlast(tab, n) == 1
				&& checkpos_row_backlast(tab, n) == 1
				&& checkpos_row_forlast(tab, n) == 1)
			return (1);
		return (0);
	}
	else
	{
		if (no_identicalpos(tab, n, x, y) == 1
				&& checkpos_clmn_back(tab, n, x) == 1
				&& checkpos_clmn_for(tab,n, x) == 1
				&& checkpos_row_back(tab, n, y) == 1
				&& checkpos_row_for(tab, n, y) == 1)
			return (1);
		return (0);
	}
}

int	uncorrect_recursive(t_case *tab, int n, int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i <= n && j == 0)
	{	
		get_case(tab, n, x, y)->value = i;
		if (x == 3  && y == 4) 
		{
			display_tab(tab,n);
			printf("\n");
		}
		if (good_positionning(tab, n, x, y) == 1)
		{
			if (x + 1 == n + 1 && y < n)
				j = fill_recursive(tab, n, 1, y + 1);
			else if (x == n && y == n)
			{
				return (1);
			}
			else if (x + 1 != n + 1)
				j = fill_recursive(tab, n, x + 1, y);
		}
		i++;
		if (i > n && j == 0)
			get_case(tab, n, x, y)->value = 0;
	}
	return (j);
}

int	hardcorrect_recursive(t_case *tab, int n, int x, int y)
{
	int j;

	j = 0;
	if (x == n && y == n)
	{
		return (1);
	}
	else if (x + 1 == n + 1)
		j = fill_recursive(tab, n, 1, y + 1);
	else if (x + 1 < n + 1)
		j = fill_recursive(tab, n, x + 1, y);
	return (j);
}

int	fill_recursive(t_case *tab, int n, int x, int y){
	int j;

	j = 0;
	if (!get_case(tab, n, x, y)->hard_correct)
		j = uncorrect_recursive(tab, n, x, y);
	else
		j = hardcorrect_recursive(tab, n, x, y);
	return (j);
}
