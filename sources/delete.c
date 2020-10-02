/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:26:08 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:55:37 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			delete_token(char ***token)
{
	int i;

	i = 0;
	while ((*token)[i] != NULL)
		ft_strdel(&(*token)[i++]);
	free(*token);
	*token = NULL;
}

void			destroy_map(t_player_data *player)
{
	ft_memdel((void**)&player->board->heat_map);
	ft_memdel((void**)&player->board);
}

void			destroy_token(t_player_data *player)
{
	delete_token(&player->token->piece);
	ft_memdel((void**)&player->token);
}

void			delete_splitted_line(char ***splitted_line)
{
	int i;

	i = 0;
	while ((*splitted_line)[i] != NULL)
		ft_strdel(&(*splitted_line)[i++]);
	free(*splitted_line);
	*splitted_line = NULL;
}
