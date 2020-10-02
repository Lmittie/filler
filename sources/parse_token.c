/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:03:54 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:57:11 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	parse_token(t_player_data *player)
{
	int		i;
	char	*line;

	i = 0;
	while (i < player->token->height)
	{
		if (get_next_line(0, &line) != 1)
		{
			player->token->piece[i] = NULL;
			destroy_token(player);
			return (0);
		}
		if (ft_strlen(line) != (size_t)player->token->width
		|| (ft_strchr(line, '.') == NULL && ft_strchr(line, '*') == NULL))
		{
			ft_strdel(&line);
			player->token->piece[i] = NULL;
			destroy_token(player);
			return (0);
		}
		player->token->piece[i] = line;
		i++;
	}
	player->token->piece[i] = NULL;
	return (1);
}

static int	init_token_size(t_player_data *player, const char **line)
{
	if (ft_strcmp(line[0], "Piece"))
		return (0);
	if ((player->token = (t_token*)malloc(sizeof(t_token)))
			== NULL)
		return (0);
	player->token->height = ft_atoi(line[1]);
	player->token->width = ft_atoi(line[2]);
	if (player->token->height == 0 || player->token->width == 0)
	{
		ft_memdel((void**)&player->token);
		return (0);
	}
	if ((player->token->piece =
	(char**)malloc(sizeof(char*) * (player->token->height + 1)))
			== NULL)
	{
		ft_memdel((void**)&player->token);
		return (0);
	}
	if (!parse_token(player))
		return (0);
	return (1);
}

int			parse_token_size(t_player_data *player)
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
	if (!init_token_size(player, (const char**)splitted_line))
	{
		ft_strdel(&line);
		delete_splitted_line(&splitted_line);
		return (0);
	}
	ft_strdel(&line);
	delete_splitted_line(&splitted_line);
	return (1);
}
