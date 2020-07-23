/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/23 00:37:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state, t_display *display)
{
	game_state->active = true;

	game_state->texture = IMG_LoadTexture(display->renderer, "2048_texture.png");
	game_state->src_rect = carve_2048_texture();

	if (game_state->texture == NULL)
		printf("Texture does not exist\n");

	game_state->game_over = false;

	game_state->action = NONE;

	bzero(game_state->board, sizeof(game_state->board));

	srand(time(NULL));
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);

	// game_state.board[0 +  0 + 3] = 4;
	// game_state.board[0 +  4 + 3] = 2;
	game_state.board[0 +  8 + 3] = 2;
	// game_state.board[0 + 12 + 3] = 4;

	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		draw_grid(&game_state, &display);
		draw_board(&game_state, &display);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
