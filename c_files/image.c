/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:50:28 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 11:03:50 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mymlx_pixelput(t_all *vars, t_data *data)
{
	char	*dst;
	int	color;
	int	x;
	int	y;
	int	px;
	int	py;


	x = 0;
	while (x < vars->rsl.w)
	{
		y = 0;
		while (y < vars->rsl.h)
		{
			dst = data->addr + (y * data->ll + x * 
					(data->bpp / 8));
			px = (x / (vars->rsl.w / 64)) % 64;
			py = (y / (vars->rsl.h / 64)) % 64;
			color =	ft_get_xpm_pixel(&vars->spr.data[3], 
					px, py);
			if (color == 0)
				printf("px = %d, py = %d \n", px, py);
			*(unsigned int*)dst = color;
			y++;
		}
		x++;
	}
}

int	ft_get_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int*)data->addr + (x + y * 64));
	return (color);
}
