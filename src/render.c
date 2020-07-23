/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/22 20:58:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_tile(int val, int x, int y, t_display *display, t_game_context *game_state)
{
	SDL_Rect	dest;
	SDL_Rect	num_dest;

	dest.h = TILE_SIZE * SCALE;
	dest.w = TILE_SIZE * SCALE;
	dest.x = (x * SCALE * TILE_SIZE);
	dest.y = (y * SCALE * TILE_SIZE);

	SDL_SetTextureColorMod(game_state->texture, 125, 188, 198);
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[TILE]), &dest);
	// SDL_SetTextureColorMod(game_state->texture, 255, 255, 255);

	num_dest.h = TILE_SIZE;
	num_dest.w = TILE_SIZE;
	num_dest.x = (x + 1) * SCALE * TILE_SIZE - (num_dest.w) - 20;
	num_dest.y = (y) * SCALE * TILE_SIZE + 32;

	itow(val, num_dest, display);
	(void)val;
}


void	draw_board(t_game_context *game_state, t_display *display)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (game_state->board[i] != 0)
			draw_tile(game_state->board[i], i % 4, i / 4, display, game_state);
		i++;
	}
}

void	draw_grid(t_game_context *game_state, t_display *display)
{
	int	row;
	int	col;

	row = 1;
	while (row < 4)
	{
		col = 1;
		while (col < 4)
		{
			SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(display->renderer, col * TILE_SIZE * SCALE, 0, col * TILE_SIZE * SCALE, WIN_HEIGHT);
			SDL_RenderDrawLine(display->renderer, 0, row * TILE_SIZE * SCALE, WIN_WIDTH, row * TILE_SIZE * SCALE);
			col++;
		}
		row++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	(void)game_state;
}
