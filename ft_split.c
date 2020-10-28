/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:06:58 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/22 11:08:47 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*mallocword(char *str, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	if (!(dest = malloc(sizeof(*dest) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		countword(char *str, char *charset)
{
	int	i;
	int	count;
	int	mot;

	count = 0;
	mot = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		while (str[i] && !is_sep(str[i], charset))
		{
			if (mot == 0)
			{
				count++;
			}
			mot = 1;
			i++;
		}
		mot = 0;
	}
	return (count + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		k;

	k = 0;
	if (!(dest = malloc(sizeof(*dest) * countword(str, charset))))
		return (0);
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			dest[k] = mallocword(str, charset);
			k++;
		}
		while (*str && !is_sep(*str, charset))
			str++;
	}
	dest[k] = 0;
	return (dest);
}
