/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:26:15 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/21 07:38:58 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str);

int		checkerrorbase(char *str);

int		inbase(char c, char *base);

int		atoi_base(char *str, char *base);

int		putnbr_recubase(char *dest, char *base, unsigned int nb, int index);

void	putnbr_base(char *dest, char *base, int nb)
{
	int				i;
	unsigned int	n;

	if (nb < 0)
	{
		n = -1 * nb;
		i = putnbr_recubase(dest, base, n, 0);
		dest[i] = '-';
		i++;
	}
	else
	{
		n = nb;
		i = putnbr_recubase(dest, base, n, 0);
	}
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	char	*temp;
	char	*dest;
	int		i;
	int		j;

	j = 0;
	if (checkerrorbase(base_form) == 0 || checkerrorbase(base_to) == 0)
		return (0);
	if (!(temp = malloc(sizeof(*temp) * 34)))
		return (0);
	putnbr_base(temp, base_to, atoi_base(nbr, base_form));
	i = str_len(temp);
	if (!(dest = malloc(sizeof(*dest) * (i + 1))))
	{
		free(temp);
		return (0);
	}
	j = -1;
	while (++j < i)
	{
		dest[j] = temp[i - 1 - j];
	}
	free(temp);
	dest[j] = '\0';
	return (dest);
}
