/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:07:25 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:56:22 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_hmap_row(const char *line, int *row, t_player_data *player, int i)
{
	int j;

	j = -1;
	while (++j < player->board->width)
		if (line[j] == '.')
			row[j] = 0;
		else if (line[j] == player->player_symbol)
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
		else
			return (0);
	return (1);
}

int		parse_board(t_player_data *player)
{
	char	*line;
	int		i;

	i = -1;
	if (get_next_line(0, &line) != 1)
		return (0);
	ft_strdel(&line);
	while (++i < player->board->height)
	{
		if (get_next_line(0, &line) != 1)
		{
			destroy_map(player);
			return (0);
		}
		if (((int)ft_strlen(&line[4]) != player->board->width) ||
		!fill_hmap_row(&line[4],
		&player->board->heat_map[i * player->board->width], player, i))
		{
			ft_strdel(&line);
			destroy_map(player);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}

int		init_board_size(t_player_data *player, const char **line)
{
	if (line == NULL || ft_strcmp(line[0], "Plateau"))
		return (0);
	if ((player->board = (t_board*)malloc(sizeof(t_board))) == NULL)
		return (0);
	player->board->height = ft_atoi(line[1]);
	player->board->width = ft_atoi(line[2]);
	if (player->board->height == 0 || player->board->width == 0)
	{
		ft_memdel((void**)&player->board);
		return (0);
	}
	if ((player->board->heat_map =
	(int*)malloc(sizeof(int) * (player->board->height * player->board->width)))
		== NULL)
	{
		ft_memdel((void**)&player->board);
		return (0);
	}
	if (!parse_board(player))
		return (0);
	return (1);
}

int		parse_board_size(t_player_data *player)
{
	char	*line;
	char	**splitted_line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if (!line[0] || (splitted_line = ft_strsplit(line, ' ')) == NULL)
	{
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	player->enemy_pos[0] = -1;
	player->player_pos[0] = -1;
	if (!init_board_size(player, (const char**)splitted_line))
	{
		delete_splitted_line(&splitted_line);
		return (0);
	}
	delete_splitted_line(&splitted_line);
	return (1);
}
