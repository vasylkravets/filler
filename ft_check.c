/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:22:07 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/13 13:22:13 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_check_token(char *line, t_maps *map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (!ft_isdigit(line[i]) && line)
		i++;
	map->heigth_token = ft_atoi(&line[i]);
	map->width_token = ft_atoi(ft_strrchr(line, ' '));
	map->mas_token = (char**)malloc(sizeof(char*) * (map->heigth_token + 1));
	while (j < map->heigth_token)
	{
		get_next_line(0, &line);
		map->mas_token[j] = ft_strdup(line);
		ft_strdel(&line);
		j++;
	}
	ft_strdel(&line);
	map->mas_token[j] = NULL;
}

void	ft_check_w_and_height(char *line, t_maps *map)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	map->heigth_field = ft_atoi(&line[i]);
	map->width_field = ft_atoi(ft_strrchr(line, ' '));
	map->mas_field = (char**)malloc(sizeof(char*) * (map->heigth_field + 1));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (b < map->heigth_field)
	{
		get_next_line(0, &line);
		map->mas_field[b] = ft_strdup(line + 4);
		ft_strdel(&line);
		b++;
	}
	ft_strdel(&line);
	map->mas_field[b] = NULL;
}

void	ft_check_player(t_maps *map, char *line)
{
	if (ft_atoi(&line[10]) == 1)
	{
		map->player_1 = 'O';
		map->player_2 = 'X';
	}
	else
	{
		map->player_2 = 'O';
		map->player_1 = 'X';
	}
}

void	ft_check(char *line, t_maps *map)
{
	ft_check_player(map, line);
	if (!ft_strncmp(line, "$$$ exec p2", 9) && line &&
		(line[10] == '1' || line[10] == '2'))
	{
		while (get_next_line(0, &line) > 0)
		{
			if (!ft_strncmp(line, "Plateau ", 8))
				ft_check_w_and_height(line, map);
			if (!ft_strncmp(line, "Piece ", 6))
			{
				ft_check_token(line, map);
				if (ft_insert(map))
					ft_print(map);
				else
				{
					map->the_end = 1;
					ft_print(map);
				}
				ft_free(map);
				ft_strdel(&line);
			}
			if (map->all == 5)
				break ;
		}
	}
}
