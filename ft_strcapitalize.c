/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:28:49 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/11 21:36:30 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
			|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && 'a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (i != 0 && ft_check(str[i - 1]) == 0 && 'a' <= str[i]
				&& str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (i != 0 && ft_check(str[i - 1]) == 1
				&& 'A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
