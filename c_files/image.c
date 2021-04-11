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


	printf("data->ll = %d, data->bpp / 8 = %d \n", data->ll, data->bpp / 8);
	x = 0;
	while (x < vars->rsl.w)
	{
		printf("(y - 20) * data->ll = %d \n", (y - 20) * data->ll);
		y = 0;
		while (y < vars->rsl.h)
		{
			dst = data->addr + (y * data->ll + x * 
					(data->bpp / 8));
			px = x / (vars->rsl.w / 32) % 64;
			py = y / (vars->rsl.h / 32) % 64;
			color =	ft_get_xpm_pixel(&vars->spr.data[3], 
					px, py);
			if (color == 0)
				printf("y / rslh / 32 = %d \n", y / (vars->rsl.h / 32));
			*(unsigned int*)dst = color;
			y++;
		}
		x++;
	}
}

int	ft_get_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	/*if (y >= 32)
		y = 31;*/
	color = *((int*)data->addr + (x * 2 + y * 128));
	return (color);
}
