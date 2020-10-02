/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:40:07 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/28 15:22:28 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ensure_one_contact(t_player_data *player, int x, int y)
{
	int contacts;
	int i;
	int j;

	contacts = 0;
	i = 0;
	while (i < player->token->height)
	{
		j = 0;
		while (j < player->token->width)
		{
			if (player->board->heat_map[(x + i) * player->board->width + j + y]
				== player->enemy_number && player->token->piece[i][j] == '*')
				return (0);
			if (player->board->heat_map[(x + i) * player->board->width + j + y]
				== player->player_number && player->token->piece[i][j] == '*')
				contacts++;
			if (contacts > 1)
				return (contacts);
			j++;
		}
		i++;
	}
	return (contacts);
}

static int		calculate_sum(t_player_data *player, int x, int y)
{
	int sum;
	int i;
	int j;

	sum = 0;
	i = 0;
	while (i < player->token->height)
	{
		j = 0;
		while (j < player->token->width)
		{
			if (player->token->piece[i][j] == '*' &&
			player->board->heat_map[(x + i) * player->board->width + j + y] > 0)
				sum +=
				player->board->heat_map[(x + i) * player->board->width + j + y];
			j++;
		}
		i++;
	}
	return (sum);
}

static int		find_min_sum(t_player_data *player, int i, int j, int min_sum)
{
	int sum;

	if (ensure_one_contact(player, i, j) == 1)
	{
		if ((sum = calculate_sum(player, i, j)) < min_sum)
		{
			min_sum = sum;
			player->position = (t_point){i, j};
		}
	}
	return (min_sum);
}

void			filler(t_player_data *player)
{
	int i;
	int j;
	int min_sum;

	i = player->player_pos[0] + 1 - player->token->height < 0 ?
		0 : player->player_pos[0] + 1 - player->token->height;
	min_sum = INT32_MAX;
	while (i < player->player_pos[1] + 1)
	{
		j = 0;
		if (player->board->height - (i + player->token->height) >= 0)
			while (j < player->board->width)
			{
				if (player->board->width - (j + player->token->width) >= 0)
					min_sum = find_min_sum(player, i, j, min_sum);
				j++;
			}
		i++;
	}
}
