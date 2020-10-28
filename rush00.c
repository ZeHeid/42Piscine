/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:39:25 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/11 21:43:03 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	put_line(char *a, char *b, char *c, int x);
int		test(int x, int y);

void	rush(int x, int y)
{
	char	*coinsup;
	char	row;
	char	column;
	char	*coininf;
	int		j;

	coinsup = "oo";
	row = '-';
	column = '|';
	coininf = "oo";
	j = 1;
	if (test(x, y) == 1)
	{
		while (j <= y)
		{
			if (j == 1)
				put_line(&coinsup[0], &row, &coinsup[1], x);
			else if (j == y)
				put_line(&coininf[0], &row, &coininf[1], x);
			else
				put_line(&column, " ", &column, x);
			j++;
		}
	}
}
