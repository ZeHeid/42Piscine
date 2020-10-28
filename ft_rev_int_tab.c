/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:01:18 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/26 09:05:15 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;
	int n;

	i = 0;
	n = size - 1;
	while (i < n / 2)
	{
		temp = tab[i];
		tab[i] = tab[n - i];
		tab[n - i] = temp;
		i++;
	}
}


int main()
{
	int tab[6] = {1,2,3,4,5,6};
	
	ft_rev_int_tab(tab, 6);
	for (int i = 0; i < 6; i ++)
	{
		printf("%d\n",tab[i]);
	}
	return 0;
}
