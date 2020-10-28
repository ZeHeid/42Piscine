/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:27:12 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/21 08:10:48 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		totalsize(int size, char **strs, char *sep)
{
	int i;
	int j;
	int res;

	i = 0;
	j = ft_strlen(sep);
	res = 0;
	while (i < size - 1)
	{
		res = res + ft_strlen(strs[i]) + j;
		i++;
	}
	res = res + ft_strlen(strs[i]);
	return (res + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(dest);
	while (src[i])
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	if (size == 0)
	{
		dest = malloc(0);
		return (dest);
	}
	i = 0;
	if (!(dest = malloc(sizeof(**strs) * totalsize(size, strs, sep))))
		return (0);
	ft_strcpy(dest, strs[i]);
	while (i + 1 < size)
	{
		ft_strcat(dest, sep);
		ft_strcat(dest, strs[i + 1]);
		i++;
	}
	return (dest);
}
