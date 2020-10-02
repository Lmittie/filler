/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_manipulation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:28:45 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 17:05:09 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ParseBoard(Board& board, const string& line) {
		stringstream ss(line);
		string row;

		ss >> row;
		ss >> board.height;
		ss >> board.width;

		getline(cin, row);

	for (int i = 0; i < board.height; ++i) {
		getline(cin, row);
		board.plateau.push_back(&row[4]);
	}
}

void	DrawBoard(const Board& board, Visual& vis) {
	int height = CalcRectHeight(board.height);
	int width = CalcRectWidth(board.width);

	for (int i = 0; i < board.height; ++i) {
		for (int j = 0; j < board.width; ++j) {
			if (tolower(board.plateau[i][j]) == 'o') {
				SDL_Rect curr_rect = SetRectangleValues(
					j * width + 100,
					i * height + 205,
					width,
					height);
				int alpha = board.plateau[i][j] == 'O' ? 240 : 125;
				vis.ChangeTextureAlpha("p1", alpha);
				SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("p1"), NULL, &curr_rect);
			} else if (tolower(board.plateau[i][j]) == 'x') {
				SDL_Rect curr_rect = SetRectangleValues(
					j * width + 100,
					i * height + 205,
					width,
					height);
				int alpha = board.plateau[i][j] == 'X' ? 240 : 125;
				vis.ChangeTextureAlpha("p2", alpha);
				SDL_RenderCopy(vis.GetRenderer(), vis.GetTexture("p2"), NULL, &curr_rect);
			}
		}
	}
}

void	GetBoard(vector<Board>& boards) {
	string line;

	while (cin.peek() != '=' && getline(cin, line)) {
		Board board;

		if (line.find("Plateau") == 0) {
			ParseBoard(board, line);
			boards.push_back(board);
			break ;
		}
	}
}
