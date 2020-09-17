/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:35:08 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/10 14:25:16 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	InitTextures(Visual& vis) {
	vis.CreateTexture("images/cat.bmp", "p1");
	vis.CreateTexture("images/dog.bmp", "p2");
	vis.CreateTexture("images/logo.bmp", "logo");
	vis.CreateTexture("images/plams.bmp", "background");
	vis.CreateTexture("images/event.bmp", "event");
	vis.CreateTexture("images/cat_winner.bmp", "cat winner");
	vis.CreateTexture("images/dog_winner.bmp", "dog winner");
	vis.CreateTexture("images/player1.bmp", "player1");
	vis.CreateTexture("images/player2.bmp", "player2");
	vis.CreateTexture("images/friendship_winner.bmp", "friendship winner");
}

int		main(void) {
	try {
		Visual vis;
		vector<Board> boards;

		InitTextures(vis);

		HandleEvents(vis, boards);
	} catch(exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}