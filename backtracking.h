/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:28:58 by rdelahay          #+#    #+#             */
/*   Updated: 2020/10/18 14:12:11 by rdelahay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_H
# define BACKTRACKING_H

int	checkpos_row_for(t_case *tab, int n, int y);

int	checkpos_row_back(t_case *tab, int n, int y);

int checkpos_clmn_for(t_case *tab, int n, int x);

int checkpos_clmn_back(t_case *tab, int n, int x);

int no_identicalpos(t_case *tab, int n, int x, int y);

#endif
