/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:33:58 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/09 21:08:48 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALIZER_H

# define FILLER_VISUALIZER_H

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <sstream>
# include <cctype>
# include <SDL2/SDL.h>

using namespace std;

# define WIDTH 1400
# define HEIGHT 1200

struct	Board
{
	int width = 0;
	int height = 0;
	vector<string> plateau;
};

class Visual {
	public:
		Visual() {
			if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
				throw runtime_error(SDL_GetError());
			}
			win = SDL_CreateWindow("Filler Game",
									100,
									100,
									WIDTH,
									HEIGHT,
									SDL_WINDOW_SHOWN);
			if (win == nullptr) {
				throw runtime_error(SDL_GetError());
			}
			ren = SDL_CreateRenderer(win,
									-1,
									SDL_RENDERER_ACCELERATED
									| SDL_RENDERER_PRESENTVSYNC);
			if (ren == nullptr) {
				throw runtime_error(SDL_GetError());
			}
		}
		void CreateTexture(const string& bmp_img, const string& name) {
			if (textures.find(name) == textures.end()) {
				SDL_Surface *bmp = nullptr;

				bmp = SDL_LoadBMP(bmp_img.c_str());
				if (bmp == nullptr) {
					throw runtime_error(SDL_GetError());
				}
				textureToLoad = SDL_CreateTextureFromSurface(ren, bmp);
				SDL_FreeSurface(bmp);
				if (textureToLoad == nullptr) {
					throw runtime_error(SDL_GetError());
				}
				textures[name] = textureToLoad;
			}
		}
		void ChangeTextureAlpha(const string& name, int alpha_value) {
			SDL_SetTextureAlphaMod(textures[name], alpha_value);
		}
		void ChangeTextureColor(const string& name, int r, int g, int b) {
			SDL_SetTextureColorMod(textures[name], r, g, b);
		}
		SDL_Texture *GetTexture(const string& name) {
			if (textures.find(name) == textures.end()) {
				return nullptr;
			} else
				return textures[name];
		}
		~Visual() {
			for (auto& texture : textures) {
				SDL_DestroyTexture(texture.second);
			}
			SDL_DestroyTexture(textureToLoad);
			textures.erase(textures.begin(), textures.end());
			SDL_DestroyRenderer(ren);
			SDL_DestroyWindow(win);

			SDL_Quit();
		}
		SDL_Renderer *GetRenderer() {
			return ren;
		}
	private:
		SDL_Window *win;
		SDL_Renderer *ren;
		map <string, SDL_Texture*> textures;
		SDL_Texture *textureToLoad;
};

int			CalcRectWidth(int width);
int			CalcRectHeight(int height);
SDL_Rect	SetRectangleValues(int x, int y, int w, int h);

void		HandleEvents(Visual& vis, vector<Board>& boards);

void		GetBoard(vector<Board>& boards);
void		DrawBoard(const Board& board, Visual& vis);
void		ParseBoard(Board& board, const string& line);

#endif
