/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:15:03 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 19:02:32 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int diffs;

	i = 0;
	diffs = str_len(str) - str_len(to_find);
	while (i <= diffs && diffs != str_len(str)
			&& to_find[j])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j])
			{
				if (str[i + j] == to_find[j])
					j++;
				else
					break ;
			}
		}
		i++;
	}
	if (j == 0)
		return (0);
	return (&str[i]);
}
