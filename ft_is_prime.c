/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:33:39 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 11:46:13 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int min;
	int max;

	min = 2;
	max = nb;
	if (nb <= 1)
		return (0);
	while (min < max)
	{
		if (nb % min == 0)
			return (0);
		max = nb / min;
		if (min == 2)
			min++;
		else
			min = min + 2;
	}
	return (1);
}
