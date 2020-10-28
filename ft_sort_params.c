/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:48:40 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/16 14:15:52 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**sort_arg(char **arg, int size)
{
	int		i;
	char	*c;

	i = 1;
	while (i <= size - 1)
	{
		if (ft_strcmp(arg[i], arg[i + 1]) >= 1)
		{
			c = arg[i + 1];
			arg[i + 1] = arg[i];
			arg[i] = c;
			i = 1;
		}
		else
			i++;
	}
	return (arg);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	sort_arg(argv, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
