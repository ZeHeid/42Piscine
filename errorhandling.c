/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:24:17 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:06:48 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "errorhandling.h"
#include "strutils.h"

void	put_error(int color)
{
	write(1, FT_COLOR_RED, color * 6);
	write(1, "Error\n", 6);
	write(1, FT_COLOR_NRM, color * 5);
}

int		*ft_err(int *ptr)
{
	free(ptr);
	return (NULL);
}

_Bool	check_args(int *clues, int n)
{
	int	i;

	if (clues == NULL)
		return (0);
	if (n % 4 != 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (clues[i] > n / 4)
			return (0);
		++i;
	}
	return (1);
}
