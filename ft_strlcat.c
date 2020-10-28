/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:57:34 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/13 19:03:08 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlen(char *str)
{
	unsigned	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int	i;
	unsigned	int j;
	unsigned	int	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	if (i == 0)
		return (j);
	if (i < size)
	{
		while (k < (size - 1) - i && src[k])
		{
			dest[i + k] = src[k];
			k++;
		}
		dest[i + k] = '\0';
		return (j + i);
	}
	else
		return (size + j);
}
