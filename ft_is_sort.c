/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:29:19 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/28 16:06:56 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (count > 0)
				return (0);
			count = -1;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (count < 0)
				return (0);
			count = 1;
		}
		i++;
	}
	return (1);
}
