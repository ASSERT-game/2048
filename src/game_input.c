/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2020/07/22 19:41:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	process_user_input(t_game_context *game_state)
{
	SDL_Event		e;
	const Uint8		*keystate;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			game_state->active = false;
			break ;
		}
	}
	keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_LEFT])
		game_state->action = LEFT;
	else if (keystate[SDL_SCANCODE_RIGHT])
		game_state->action = RIGHT;
	else if (keystate[SDL_SCANCODE_UP])
		game_state->action = UP;
	else if (keystate[SDL_SCANCODE_DOWN])
		game_state->action = DOWN;
}
