/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:29:25 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:56:38 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	init_player_number(t_player_data *player, const char **line)
{
	if (line[0] == NULL || ft_strcmp(line[0], "$$$") ||
		ft_strcmp(line[1], "exec"))
		return (0);
	if (line[2][1] == '1')
	{
		player->player_number = -1;
		player->enemy_number = -2;
		player->player_symbol = 'O';
		player->enemy_symbol = 'X';
	}
	else if (line[2][1] == '2')
	{
		player->player_number = -2;
		player->enemy_number = -1;
		player->player_symbol = 'X';
		player->enemy_symbol = 'O';
	}
	else
		return (0);
	return (1);
}

int			parse_player_number(t_player_data *player)
{
	char *line;
	char **splitted_line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if ((splitted_line = ft_strsplit(line, ' ')) == NULL)
	{
		ft_strdel(&line);
		return (0);
	}
	if (!init_player_number(player, (const char**)splitted_line))
	{
		ft_strdel(&line);
		delete_splitted_line(&splitted_line);
		return (0);
	}
	ft_strdel(&line);
	delete_splitted_line(&splitted_line);
	return (1);
}
