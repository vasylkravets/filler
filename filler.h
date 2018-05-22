/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkravets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:22:36 by vkravets          #+#    #+#             */
/*   Updated: 2018/02/13 13:22:37 by vkravets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_maps
{
	char		player_1;
	char		player_2;
	int			width_field;
	int			heigth_field;
	char		**mas_field;
	int			width_token;
	int			heigth_token;
	char		**mas_token;
	int			return_x;
	int			return_y;
	int			method;
	int			*mas;
	int			the_end;
	int			p1_point_x;
	int			p1_point_y;
	int			p2_point_x;
	int			p2_point_y;
	int			all;
}				t_maps;

int				value_for_return(int x, int y, t_maps *map);
int				search_coord(t_maps *map);
int				search_coord1(t_maps *map);
int				search_coord2(t_maps *map);
int				search_coord3(t_maps *map);
void			ft_free(t_maps *map);
void			ft_print(t_maps *map);
void			ft_reset(t_maps *map);
int				ft_insert(t_maps *map);
void			ft_check(char *line, t_maps *map);
void			check_coord_field(t_maps *map);
int				search_coord(t_maps *map);

#endif
