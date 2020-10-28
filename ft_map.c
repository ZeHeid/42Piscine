/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:09:07 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/23 09:20:40 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *cpy;
	int i;

	i = 0;
	if (!(cpy = malloc(sizeof(*cpy) * length)))
		return (0);
	while (i < length)
	{
		cpy[i] = f(tab[i]);
		i++;
	}
	return (cpy);
}
