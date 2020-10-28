/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:49:43 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:05:15 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

t_case			*new_s_case(int n)
{
	t_case			*tab;
	int				i;
	int				k;

	tab = malloc(sizeof(*tab) * (n + 2) * (n + 2));
	i = 0;
	k = 0;
	while (i < (n + 2) * (n + 2))
	{
		tab[i].value = 0;
		tab[i].hard_correct = 0;
		++i;
	}
	return (tab);
}

t_case			*get_case(t_case *tab, int n, int x, int y)
{
	if ((n + 2) * y + x < (n + 2) * (n + 2) && (n + 2) * y + x >= 0)
		return (&tab[(n + 2) * y + x]);
	return (NULL);
}

void			fill_border(t_case *tab, int n, int *sides)
{
	int	i;

	i = 0;
	while (i < n)
	{
		get_case(tab, n, i + 1, 0)->value = sides[i];
		++i;
	}
	while (i < n * 2)
	{
		get_case(tab, n, i % n + 1, n + 1)->value = sides[i];
		++i;
	}
	while (i < n * 3)
	{
		get_case(tab, n, 0, i % n + 1)->value = sides[i];
		++i;
	}
	while (i < n * 4)
	{
		get_case(tab, n, n + 1, i % n + 1)->value = sides[i];
		++i;
	}
}
