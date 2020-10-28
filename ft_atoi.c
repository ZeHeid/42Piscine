/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:12:32 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/15 16:53:50 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	indexandsigne(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1 * j;
		i++;
	}
	return (j * i);
}

int	ft_atoi(char *str)
{
	int res;
	int i;
	int j;

	res = 0;
	j = 1;
	i = indexandsigne(str);
	if (i < 0)
	{
		i = -1 * i;
		j = -1;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + j * str[i] % 48;
		i++;
	}
	return (res);
}
