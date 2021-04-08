/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int	fd;
	char	*line;
	char	**texpath;
	char	**map;
	t_rgb	ground;
	t_rgb	sky;
	int	groundcolor;
	int	skycolor;
	void	*mlx;
	void	*win;
	t_data	img;
	int	fstdmsz;
	int	w;
	int	h;
	int	i;
	int	j;

	printf("start \n");
	w = 0;
	h = 0;
	fstdmsz = 1;
	if (!(map = malloc(sizeof(char*))))
		return (0);
	map[0] = NULL;
	if (!(texpath = malloc(sizeof(char*) * 6)))
		return (0);
	texpath[5] = NULL;
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == 2)
		{
			j = ft_parse_tex(line, texpath);
			if (j == 1)
				printf("parse tex : SUCCES \n");
		}
		else if (ft_check_line(line) == 1)
		{
			ft_parse_rsl(line, &w, &h);
			printf("w = %d, h = %d \n", w, h);
		}
		else if (ft_check_line(line) == 3)
		{
			if (line[0] == 'F')
				ft_rgb_fill(&ground, line);
			else
				ft_rgb_fill(&sky, line);
		}
		else if (ft_check_line(line) == 4)
		{
			printf("before parse map \n");
			map = ft_parse_map(line, map);
		}
		/*if (ft_parse(line) != 1)
			return (0);*/
		/*if (!(map = ft_firstdim_mapalloc(line, map, fstdmsz)))
			return (0);
		fstdmsz++;*/
	}
	printf ("ground rgb = %u,%u,%u \n", ground.r, ground.g, ground.b);
	printf ("sky rgb = %u,%u,%u \n", sky.r, sky.g, sky.b);
	groundcolor = ft_rgbtocolor(ground.r, ground.g, ground.b);
	skycolor = ft_rgbtocolor(sky.r, sky.g, sky.b);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "SandG");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.e);
	ft_mymlx_pixelput(&img, skycolor, groundcolor);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	printf("is map walled ? %d \n", ft_ismap_walled(map));
	i = 0;
	while (texpath[i])
	{
		printf("texpath[%d] = %s \n", i, texpath[i]);
		free(texpath[i]);
		i++;
	}
	free(texpath);
	i = 0;
	while(map[i])
	{
		printf("map[%d] = %s \n", i , map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
	return (0);
}
