/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:14:32 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:56:47 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_new_cells(t_player_data *player, const char *line, int *row, int i)
{
	int j;

	j = -1;
	while (++j < player->board->width && line[j])
		if (line[j] == '.')
			row[j] = 0;
		else if (line[j] == player->player_symbol ||
		line[j] == ft_tolower(player->player_symbol))
		{
			if (player->player_pos[0] == -1)
				player->player_pos[0] = i;
			row[j] = player->player_number;
			player->player_pos[1] = i;
		}
		else if (line[j] == player->enemy_symbol ||
		line[j] == ft_tolower(player->enemy_symbol))
		{
			if (player->enemy_pos[0] == -1)
				player->enemy_pos[0] = i;
			row[j] = player->enemy_number;
			player->enemy_pos[1] = i;
		}
}

int		read_board_size(t_player_data *player)
{
	char	*line;
	char	**splitted_line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if ((splitted_line = ft_strsplit(line, ' ')) == NULL)
	{
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	if (splitted_line[0] == NULL ||
		ft_strcmp(splitted_line[0], "Plateau") ||
		ft_atoi(splitted_line[1]) != player->board->height ||
		ft_atoi(splitted_line[2]) != player->board->width)
	{
		delete_splitted_line(&splitted_line);
		return (0);
	}
	delete_splitted_line(&splitted_line);
	return (1);
}

int		read_board(t_player_data *player)
{
	char	*line;
	int		i;

	if (!read_board_size(player))
		return (0);
	if (get_next_line(0, &line) != 1)
		return (0);
	ft_strdel(&line);
	player->enemy_pos[0] = -1;
	player->player_pos[0] = -1;
	i = 0;
	while (i < player->board->height)
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		fill_new_cells(player, &line[4],
		&player->board->heat_map[i * player->board->width], i);
		ft_strdel(&line);
		i++;
	}
	return (1);
}
