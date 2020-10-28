/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:50:30 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:06:04 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct	s_case
{
	int				value;
	_Bool			hard_correct;
}				t_case;

t_case			*new_s_case(int n);

void			fill_border(t_case *tab, int n, int *sides);

void			prefill_col(t_case *tab, int n);
void			prefill_line(t_case *tab, int n);

t_case			*get_case(t_case *tab, int n, int x, int y);

#endif
