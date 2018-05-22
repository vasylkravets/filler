/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:16:28 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/15 11:16:30 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_subfunc(t_maps *map, int x, int y)
{
	if (map->mas_field[y][x] == map->player_1 ||
		map->mas_field[y][x] == map->player_1 + 32)
	{
		map->p1_point_x = x;
		map->p1_point_y = y;
	}
	if (map->mas_field[y][x] == map->player_2 ||
		map->mas_field[y][x] == map->player_2 + 32)
	{
		map->p2_point_x = x;
		map->p2_point_y = y;
	}
}

void	ft_method(t_maps *map)
{
	int x;
	int y;

	y = 0;
	if (map->p1_point_x == -1 && map->p1_point_y == -1 &&
		map->p2_point_x == -1 && map->p2_point_y == -1)
	{
		while (y < map->heigth_field)
		{
			x = 0;
			while (x < map->width_field)
			{
				ft_subfunc(map, x, y);
				x++;
			}
			y++;
		}
		if (map->p1_point_y < map->p2_point_y)
		{
			map->method = 1;
		}
		else
			map->method = 0;
	}
}

void	butt(t_maps *map)
{
	if (map->method == 0)
		map->method = 3;
	else if (map->method == 1)
		map->method = 2;
	else if (map->method == 2)
		map->method = 1;
	else if (map->method == 3)
		map->method = 0;
}

int		ft_insert(t_maps *map)
{
	ft_method(map);
	butt(map);
	if (map->method == 0)
	{
		return (search_coord(map));
	}
	else if (map->method == 1)
	{
		return (search_coord3(map));
	}
	else if (map->method == 2)
	{
		return (search_coord2(map));
	}
	else if (map->method == 3)
	{
		return (search_coord1(map));
	}
	else
		return (search_coord(map));
}
