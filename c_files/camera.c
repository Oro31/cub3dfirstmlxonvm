/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 10:46:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

char	ft_define_cam(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->box[i])
	{
		j = 0;
		while (map->box[i][j])
		{
			if (ft_isdir(map->box[i][j]))
			{
				map->cam.posx = j;
				map->cam.posy = i;
				printf("dir : %c \n", map->box[i][j]);
				return (map->box[i][j]);
			}
			j++;
		}
		i++;
	}
	return ('\0');
}
