/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/22 21:29:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	slide_board(int	*board, int action)
{
	int	i;
	int	j;

	printf("ACT: %d\n", action);
	i = 0;
	while (i < 4)
	{
		j = i;
		while (j - 1 >= 0 && board[j - 1] == 0)
			j--;

		if (j > 0 && board[i] == board[j - 1])
		{
			board[j - 1] += board[i];
			board[i] = 0;
		}
		else if (j >= 0 && board[j] == 0 && board[i] != 0)
		{
			board[j] = board[i];
			board[i] = 0;
		}
		i++;
	}
}

void	update_game_state(t_game_context *game_state)
{

	if (game_state->action != NONE)
		slide_board(game_state->board, game_state->action);

	game_state->action = NONE;
}
