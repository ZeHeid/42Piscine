/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:19:02 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 16:41:35 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	if (nb == 1)
		return (1);
	while (i <= power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
