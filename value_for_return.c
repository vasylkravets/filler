/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_for_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:40:05 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/22 14:40:07 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_valid(int y, int x, t_maps *map, int b)
{
	int y1;
	int x1;

	y1 = 0;
	b = 0;
	while (y1 < map->heigth_token)
	{
		x1 = 0;
		while (x1 < map->width_token)
		{
			if (map->mas_token[y1][x1] == '*' &&
				(map->mas_field[y + y1][x + x1] == map->player_1 + 32 ||
			map->mas_field[y + y1][x + x1] == map->player_1))
				b++;
			if (map->mas_token[y1][x1] == '*' &&
				(map->mas_field[y + y1][x + x1] == map->player_2 + 32 ||
			map->mas_field[y + y1][x + x1] == map->player_2))
				return (0);
			x1++;
		}
		y1++;
	}
	if (b == 1)
		return (1);
	return (0);
}

int		valid_size(int x, int y, t_maps *map)
{
	int b;

	b = 0;
	if (map->width_field < x + map->width_token ||
		map->heigth_field < y + map->heigth_token)
		return (0);
	else
		return (check_valid(y, x, map, b));
}

int		value_for_return(int x, int y, t_maps *map)
{
	if (valid_size(x, y, map))
	{
		map->return_x = x;
		map->return_y = y;
		return (1);
	}
	return (0);
}
