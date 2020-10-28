/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:07:47 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 20:56:36 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_recursive(int nb)
{
	char c;

	if (nb / 10 != 0)
		ft_putnbr_recursive(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int i;

	i = nb;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			i = -1 * nb;
		}
		ft_putnbr_recursive(i);
	}
}
