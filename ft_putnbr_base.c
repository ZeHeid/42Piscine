/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:20:04 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/15 16:49:24 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	str_len(char *str)
{
	unsigned	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				baseisvalide(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

void			recursive(unsigned	int nb, char *base, unsigned	int size)
{
	if (nb / size != 0)
		recursive(nb / size, base, size);
	write(1, &base[nb % size], 1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned	int i;
	unsigned	int s;

	s = str_len(base);
	if (baseisvalide(base) == 1)
	{
		if (nbr < 0)
		{
			i = -1 * nbr;
			write(1, "-", 1);
		}
		else
			i = nbr;
		recursive(i, base, s);
	}
}
