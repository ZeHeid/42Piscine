/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:46:38 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 13:21:08 by rdelahay         ###   ########lyon.fr   */
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

int	ft_find_next_prime(int nb)
{
	int test;

	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb) == 1)
		return (nb);
	if (nb % 2 == 0)
		test = nb + 1;
	else
		test = nb + 2;
	while (ft_is_prime(test) == 0)
		test = test + 2;
	return (test);
}
