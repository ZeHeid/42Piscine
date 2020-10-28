/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:27:04 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/15 09:13:47 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int min;
	int max;
	int mid;

	min = 1;
	max = 46341;
	if (nb < 46341)
		max = nb;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (nb);
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			min = mid + 1;
		else
			max = mid - 1;
	}
	if (mid * mid != nb)
		return (0);
	return (mid);
}
