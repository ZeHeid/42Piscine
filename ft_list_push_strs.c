/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:35:48 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/28 15:00:10 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin;
	t_list	*temp;
	int		i;

	i = 0;
	if (size == 0)
		return (0);
	begin = ft_create_elem(strs[0]);
	temp = begin;
	while (strs[++i])
	{
		temp->next = ft_create_elem(strs[i]);
		temp = temp->next;
	}
	return (begin);
}
