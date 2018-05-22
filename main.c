/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:45:54 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/13 15:45:59 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free(t_maps *map)
{
	int i;

	i = 0;
	while (i < map->heigth_field)
	{
		free(map->mas_field[i]);
		i++;
	}
	free(map->mas_field);
	i = 0;
	while (i < map->heigth_token)
	{
		free(map->mas_token[i]);
		i++;
	}
	free(map->mas_token);
}

void	ft_print(t_maps *map)
{
	if (map->the_end == 1)
	{
		map->all = 5;
		ft_putnbr_fd(0, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(0, 1);
	}
	else
	{
		ft_putnbr_fd(map->return_y, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(map->return_x, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_reset(t_maps *map)
{
	map->width_field = 0;
	map->heigth_field = 0;
	map->width_token = 0;
	map->heigth_token = 0;
	map->player_1 = '\0';
	map->player_2 = '\0';
	map->return_x = -1;
	map->return_y = -1;
	map->method = -1;
	map->p1_point_x = -1;
	map->p1_point_y = -1;
	map->p2_point_x = -1;
	map->p2_point_y = -1;
	map->the_end = 0;
}

int		main(void)
{
	char	*line;
	t_maps	map;

	ft_reset(&map);
	if (get_next_line(0, &line) > 0 && line)
	{
		ft_check(line, &map);
		ft_strdel(&line);
	}
	else
	{
		dprintf(2, "ERROR\n");
	}
	return (0);
}
