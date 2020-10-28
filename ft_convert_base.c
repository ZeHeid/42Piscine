/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:55:59 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/20 17:20:36 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkerrorbase(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == ' '
				|| str[i] == '+' || str[i] == '-')
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

int	inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base)
{
	int i;
	int j;
	int res;
	int l;

	i = 0;
	j = 1;
	res = 0;
	l = str_len(base);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (inbase(str[i], base) != -1)
	{
		res = res * l + j * inbase(str[i], base);
		i++;
	}
	return (res);
}

int	putnbr_recubase(char *dest, char *base, unsigned int nb, int index)
{
	int size;

	size = str_len(base);
	dest[index] = base[nb % size];
	if (nb / size != 0)
		return (putnbr_recubase(dest, base, nb / size, index + 1));
	return (index + 1);
}
