/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/23 00:33:59 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	slide_line(int	*board, int action, int row_offset, int col_offset, int delta)
{
	int	i;
	int	j;
	int	offset;

	i = 0;

	if (action == DOWN)
		i = 12;
	else if (action == RIGHT)
		i = 3;

	offset =  row_offset * 4 + col_offset;
	while (0 <= i && i < 4 * abs(delta))
	{
		j = i;
		while ((0 <= j - delta && j - delta < 4 * abs(delta)) && board[offset + j - delta] == 0)
			j -= delta;

		if (j > 0 && board[offset + i] == board[offset + j - delta] && !(action == RIGHT && j == 3))
		{
			board[offset + j - delta] += board[offset + i];
			board[offset + i] = 0;
		}
		else if (j >= 0 && board[offset + j] == 0 && board[offset + i] != 0)
		{
			board[offset + j] = board[offset + i];
			board[offset + i] = 0;
		}
		i += delta;
	}
}

void	slide_board(int	*board, int action)
{
	int	delta;
	int	row_active;
	int	col_active;

	delta = 0;
	row_active = 0;
	col_active = 0;
	if (action == LEFT)
	{
		delta = 1;
		row_active = 1;
	}
	else if (action == UP)
	{
		delta = 4;
		col_active = 1;
	}
	else if (action == DOWN)
	{
		delta = -4;
		col_active = 1;
	}
	else if (action == RIGHT)
	{
		delta = -1;
		row_active = 1;
	}

	slide_line(board, action, 0 * row_active, 0 * col_active, delta);
	slide_line(board, action, 1 * row_active, 1 * col_active, delta);
	slide_line(board, action, 2 * row_active, 2 * col_active, delta);
	slide_line(board, action, 3 * row_active, 3 * col_active, delta);
}

void	spawn_tiles(int *board)
{
	int	i;
	int	spawn_chance;

	i = 0;
	while (i < 16)
	{
		if (board[i] == 0)
		{
			spawn_chance = rand() % 10;
			if (spawn_chance < 2)
				board[i] = 2;
			else if (spawn_chance < 3)
				board[i] = 4;
		}
		i++;
	}
}

void	update_game_state(t_game_context *game_state)
{

	if (game_state->action != NONE)
	{
		slide_board(game_state->board, game_state->action);
		spawn_tiles(game_state->board);
	}

	game_state->action = NONE;
}
