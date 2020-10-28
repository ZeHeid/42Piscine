/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:21:39 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 16:45:05 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power > 0)
	{
		if (nb == 1)
			return (1);
		if (nb == 0)
			return (0);
		return (nb * ft_recursive_power(nb, power - 1));
	}
	else if (power == 0)
		return (1);
	return (0);
}
