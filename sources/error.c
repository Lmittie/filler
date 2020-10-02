/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:36:51 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:36:59 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				error(void)
{
	if (errno)
		perror("Error occurred");
	return (0);
}
