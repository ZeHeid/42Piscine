/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:57:04 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/28 16:35:24 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int		ft_strs_lem(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int i;
	int j;
	int min;

	j = 0;
	while (j != ft_strs_lem(tab))
	{
		i = j;
		min = i;
		while (tab[i])
		{
			if (cmp(tab[min], tab[i]) > 0)
				min = i;
			i++;
		}
		ft_swap(&tab[j], &tab[min]);
		j++;
	}
}
