/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:11:06 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/23 07:38:16 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strtab;
	int					i;

	i = 0;
	if (!(strtab = malloc(sizeof(*strtab) * (ac + 1))))
		return (0);
	while (i < ac)
	{
		strtab[i].size = str_len(av[i]);
		strtab[i].str = av[i];
		if (!(strtab[i].copy = malloc(sizeof(**av) * (strtab[i].size + 1))))
			return (0);
		ft_strcpy(strtab[i].copy, av[i]);
		i++;
	}
	strtab[i].str = 0;
	return (strtab);
}
