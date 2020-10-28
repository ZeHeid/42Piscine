/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:20:41 by hroussea          #+#    #+#             */
/*   Updated: 2020/10/18 14:06:52 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORHANDLING_H
# define ERRORHANDLING_H

void	put_error(int color);

int		*ft_err(int *ptr);

_Bool	check_args(int *clues, int n);

#endif
