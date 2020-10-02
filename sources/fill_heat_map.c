/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:34:10 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/06 21:53:12 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	calculate_heat_map(t_player_data *player, int x, int y)
{
	int i;
	int j;
	int dist;
	int min_dist;

	min_dist = player->board->height * player->board->width;
	i = player->enemy_pos[0];
	while (i < player->enemy_pos[1] + 1)
	{
		j = 0;
		while (j < player->board->width)
		{
			if (player->board->heat_map[i * player->board->width + j]
				== player->enemy_number)
			{
				dist = ft_abs(i - x) + ft_abs(j - y);
				if (dist < min_dist)
					min_dist = dist;
			}
			j++;
		}
		i++;
	}
	return (min_dist);
}

void		fill_heat_map(t_player_data *player)
{
	int i;
	int j;

	i = 0;
	while (i < player->board->height)
	{
		j = 0;
		while (j < player->board->width)
		{
			if (player->board->heat_map[i * player->board->width + j] == 0)
				player->board->heat_map[i * player->board->width + j] =
											calculate_heat_map(player, i, j);
			j++;
		}
		i++;
	}
}
