/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:50:27 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/12 13:19:13 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_write_hexa(unsigned	char c, char *tab)
{
	write(1, "\\", 1);
	write(1, &tab[c / 16], 1);
	write(1, &tab[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (127 >= str[i] && str[i] < 32)
			str_write_hexa(str[i], "0123456789abcdef");
		else
			write(1, &str[i], 1);
		i++;
	}
}
