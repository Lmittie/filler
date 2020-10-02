/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:22:49 by lmittie           #+#    #+#             */
/*   Updated: 2020/03/06 16:54:08 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		CalcRectHeight(int height) {
	return (HEIGHT - 200) / height;
}

int		CalcRectWidth(int width) {
	return (WIDTH - 200) / width;
}

SDL_Rect SetRectangleValues(int x, int y, int w, int h) {
	SDL_Rect Rectangle;

	Rectangle.x = x;
	Rectangle.y = y;
	Rectangle.w = w;
	Rectangle.h = h;

	return Rectangle;
}