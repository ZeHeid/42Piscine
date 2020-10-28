/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:32:12 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 11:34:06 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING2_H
# define BACKTRACKING2_H

int	good_positionning(t_case *tab, int n, int x, int y);

int uncorrect_recursive(t_case *tab, int n, int x, int y);

int hardcorrect_recursive(t_case *tab, int n, int x, int y);

int fill_recursive(t_case *tab, int n, int x, int y);

#endif
