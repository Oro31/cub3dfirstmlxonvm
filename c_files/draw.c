/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel_on_img(t_data *img, int color, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	ft_get_visual(t_all *vars)
{
	float	wall;
	int	i;
	int	j;
	int	e;

	if (!(wall = malloc(sizeof(float) * vars->rsl.w)))
		return (0);
	i = 0;
	while (i < vars->rsl.w)
	{
		j = -1;
		e = (vars->rsl.h - ((64 * 500) / wall[i])) / 2;
		while (++j < e)
			ft_put_pixel_on_img(&vars->img, vars->sky.color, i, j);
		while (++j < (vars->rsl.h - e))
			ft_put_pixel_on_img(&vars->img, 
					ft_myxpm_pixelput(&vars, e, i, j),
					i, j);
		while (++j < vars->rsl.h)
			ft_put_pixel_on_img(&vars->img, vars->ground.color);
	}

}

void	ft_draw(t_all *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->rsl.w, vars->rsl.h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, 
			&vars->img.ll, &vars->img.e);
	ft_mymlx_pixelput(vars, &vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
