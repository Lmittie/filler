/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:39:07 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:40:03 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			print(const t_point *position)
{
	ft_putnbr(position->x);
	write(1, " ", 1);
	ft_putnbr(position->y);
	write(1, "\n", 1);
}
