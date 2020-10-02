/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:11:09 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 20:56:01 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <stdio.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_board
{
	int	height;
	int	width;
	int	*heat_map;
}				t_board;

typedef struct	s_token
{
	int		height;
	int		width;
	char	**piece;
}				t_token;

typedef struct	s_player_data
{
	char			player_number;
	char			enemy_number;

	t_token			*token;
	t_board			*board;

	int				enemy_pos[2];
	int				player_pos[2];

	t_point			position;

	char			player_symbol;
	char			enemy_symbol;
}				t_player_data;

int				parse_player_number(t_player_data *player);
int				parse_board_size(t_player_data *player);
int				parse_token_size(t_player_data *player);

void			fill_heat_map(t_player_data *player);

int				read_board(t_player_data *player);

void			filler(t_player_data *player);

void			delete_splitted_line(char ***splitted_line);
void			delete_token(char ***token);
void			destroy_map(t_player_data *player);
void			destroy_token(t_player_data *player);

int				error(void);

void			print(const t_point *position);

#endif
