/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:27:04 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/10 14:34:52 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	Rendering(Visual& vis, vector<Board>& boards, const SDL_Rect& DestBg, const SDL_Rect& DestLg,
	const SDL_Rect& DestP1, const SDL_Rect& DestP2, const SDL_Rect& DestCat, const SDL_Rect& DestDog) {
		SDL_RenderClear(vis.GetRenderer());
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("background"), NULL, &DestBg);
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("logo"), NULL, &DestLg);
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("player1"), NULL, &DestP1);
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("player2"), NULL, &DestP2);
		vis.ChangeTextureAlpha("p1", 240);
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("p1"), NULL, &DestCat);
		vis.ChangeTextureAlpha("p2", 240);
		SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("p2"), NULL, &DestDog);

		GetBoard(boards);

		if (!boards.empty())
			DrawBoard(boards[boards.size() - 1], vis);
		else
			throw invalid_argument("Wrong input");
		SDL_RenderPresent(vis.GetRenderer());
}

void	CheckGameOver(bool& flag, string& winner) {
	if (cin.peek() == '=') {
		string trash;

		cin >> trash;
		cin >> trash;
		cin >> trash;

		int points_p1, points_p2;
	
		cin.ignore(1);

		cin >> points_p1;
		cin.ignore(1);
		
		if (cin.peek() == '=') {
			cin >> trash;
			cin >> trash;
			cin >> trash;

			cin.ignore(1);

			cin >> points_p2;
			if (points_p1 == points_p2)
				winner = "friendship winner";
			else if (points_p1 > points_p2)
				winner = "cat winner";
			else
				winner = "dog winner";
		} else
			winner = "cat winner";
		flag = true;
	}
}
void	ShowWinnerWindow(Visual& vis, bool& flag) {
	SDL_Rect DestEv = SetRectangleValues(WIDTH / 2 - 200, HEIGHT / 2 + 50, 400, 100);

	SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("event"), NULL, &DestEv);
	SDL_RenderPresent(vis.GetRenderer());
	flag = false;
}

void	HandleEvents(Visual& vis, vector<Board>& boards) {
	SDL_Event event;
	bool is_running = true;
	bool is_game_over = false;
	string winner;
	static unsigned long size = 0;
	bool flag = true;

	SDL_Rect DestBg = SetRectangleValues(0, 200, WIDTH, HEIGHT - 200);
	SDL_Rect DestLg = SetRectangleValues(WIDTH / 2 - 350, 10, 800, 190);
	SDL_Rect DestP1 = SetRectangleValues(100, 5, 100, 50);
	SDL_Rect DestP2 = SetRectangleValues(WIDTH - 200, 5, 100, 50);
	SDL_Rect DestCat = SetRectangleValues(120, 60, 50, 50);
	SDL_Rect DestDog = SetRectangleValues(WIDTH - 170, 60, 50, 50);

	SDL_SetRenderDrawColor(vis.GetRenderer(), 255, 255, 255, 255);
	vis.ChangeTextureAlpha("event", 200);

	while (is_running) {
		if (is_game_over && flag) {
			ShowWinnerWindow(vis, flag);
		}
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
					is_running = false;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_w && is_game_over) {
					SDL_RenderClear(vis.GetRenderer());
					SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture(winner), NULL, NULL);
					SDL_RenderPresent(vis.GetRenderer());
				}
			}
		}
		if (!is_game_over)
			Rendering(vis, boards, DestBg, DestLg, DestP1, DestP2, DestCat, DestDog);
		if (boards.size() == size && !is_game_over) {
			CheckGameOver(is_game_over, winner);
		}
		size = boards.size();
		SDL_Delay(50);
	}
}
