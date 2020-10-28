/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:16:54 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/28 14:19:48 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;

	i = 0;
	if (begin_list)
		i = 1;
	while (begin_list->next)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
