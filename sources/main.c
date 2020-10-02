/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:24:17 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:40:01 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		play(t_player_data *player)
{
	fill_heat_map(player);
	filler(player);
	print(&player->position);
	destroy_token(player);
	player->position = (t_point){0, 0};
	errno = 0;
}

int				main(void)
{
	t_player_data player;

	ft_bzero(&player, sizeof(t_player_data));
	if (!parse_player_number(&player))
		return (error());
	if (!parse_board_size(&player))
		return (error());
	if (!parse_token_size(&player))
	{
		destroy_map(&player);
		return (error());
	}
	play(&player);
	while (read_board(&player) && parse_token_size(&player))
		play(&player);
	if (errno)
		perror("Error occurred");
	destroy_map(&player);
	return (0);
}
