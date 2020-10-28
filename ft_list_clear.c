/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:02:39 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/28 15:06:56 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *temp;

	while(begin_list->next)
	{
		free_fct(begin_list->data);
		temp = begin_list->next;
		free(begin_list);
		begin_list = temp;
	}
	free_fct(begin_list->data);
	free(begin_list);
}
