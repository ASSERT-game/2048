/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:51:55 by home              #+#    #+#             */
/*   Updated: 2020/07/22 19:32:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

SDL_Rect	*carve__texture(void)
{
	int			row;
	int			col;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (2 * 1));
	while (row < 1)
	{
		col = 0;
		while (col < 2)
		{
			result[row * TILE_SIZE + col].h = TILE_SIZE;
			result[row * TILE_SIZE + col].w = TILE_SIZE;
			result[row * TILE_SIZE + col].x = (col * TILE_SIZE);
			result[row * TILE_SIZE + col].y = (row * TILE_SIZE);
			col++;
		}
		row++;
	}
	return (result);
}
