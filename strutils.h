/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:18:26 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 13:31:11 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTILS_H
# define STRUTILS_H

# define FT_COLOR_NRM  "\x1B[0m"
# define FT_COLOR_RED  "\x1B[31m"
# define FT_COLOR_GRN  "\x1B[32m"
# define FT_COLOR_YEL  "\x1B[33m"
# define FT_COLOR_BLU  "\x1B[34m"
# define FT_COLOR_MAG  "\x1B[35m"
# define FT_COLOR_CYN  "\x1B[36m"
# define FT_COLOR_WHT  "\x1B[37m"

# include "rush.h"

void	ft_putnbr_lite(int nb);

int		ft_strlen(char *str);

void	set_zero(int *a, int *b);

int		*ft_split_args(char *arg, int *n);

void	display_tab(t_case *tab, int n);

void	display_tab_pretty(t_case *tab, int n, int color);

int		ft_strcmp(char *s1, char *s2);

#endif
