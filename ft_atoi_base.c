/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:41:22 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/15 16:53:25 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	checkerrorbase(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
				|| str[i] == ' ' || str[i] == '+' || str[i] == '-')
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

int	signeatoi(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1 * j;
		i++;
	}
	return (j * i);
}

int	str_lenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int res;
	int s;
	int i;
	int j;

	res = 0;
	s = str_lenght(base);
	i = signeatoi(str);
	j = 1;
	if (checkerrorbase(base) == 1)
	{
		if (i < 0)
		{
			i = -1 * i;
			j = -1;
		}
		while (inbase(str[i], base) != -1)
		{
			res = res * s + j * inbase(str[i], base);
			i++;
		}
	}
	return (res);
}
