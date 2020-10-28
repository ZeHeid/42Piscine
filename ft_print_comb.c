/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:20:56 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/08 11:30:32 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char tab[3];

	tab[0] = '0';
	tab[1] = '1';
	tab[2] = '2';
	while (tab[0] <= '7')
	{
		while (tab[1] <= '8')
		{
			tab[2] = tab[1] + 1;
			while (tab[2] <= '9')
			{
				write(1, &tab, 3);
				if ((tab[0] != '7') || (tab[1] != '8') || (tab[2] != '9'))
					write(1, ", ", 2);
				tab[2]++;
			}
			tab[1]++;
		}
		tab[0]++;
		tab[1] = tab[0] + 1;
	}
}
