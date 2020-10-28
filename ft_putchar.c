/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmelling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:38:43 by nmelling          #+#    #+#             */
/*   Updated: 2020/10/11 20:21:17 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_line(char *a, char *b, char *c, int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(*a);
		else if (i == x)
			ft_putchar(*c);
		else
			ft_putchar(*b);
		i++;
	}
	if (x != 0)
		ft_putchar('\n');
}

int		test(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Error", 5);
		return (0);
	}
	else
		return (1);
}
