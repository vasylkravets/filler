/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:54:31 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/16 14:54:35 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		search_coord(t_maps *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->heigth_field)
	{
		x = 0;
		while (x < map->width_field)
		{
			if (value_for_return(x, y, map))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		search_coord1(t_maps *map)
{
	int y;
	int x;

	y = map->heigth_field;
	while (y > 0)
	{
		x = 0;
		while (x < map->width_field)
		{
			if (value_for_return(x, y, map))
				return (1);
			x++;
		}
		y--;
	}
	return (0);
}

int		search_coord2(t_maps *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->heigth_field)
	{
		x = map->width_field;
		while (x > 0)
		{
			if (value_for_return(x, y, map))
				return (1);
			x--;
		}
		y++;
	}
	return (0);
}

int		search_coord3(t_maps *map)
{
	int y;
	int x;

	y = map->heigth_field;
	while (y > 0)
	{
		x = map->width_field;
		while (x > 0)
		{
			if (value_for_return(x, y, map))
				return (1);
			x--;
		}
		y--;
	}
	return (0);
}
