/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:28:34 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 14:30:52 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING3_H
# define BACKTRACKING3_H

int	checkpos_row_forlast(t_case *tab, int n);

int	checkpos_row_backlast(t_case *tab, int n);

int checkpos_clmn_forlast(t_case *tab, int n);

int checkpos_clmn_backlast(t_case *tab, int n);

#endif
