/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:46:36 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/05/05 21:41:33 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(t_game *game, t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
			image.path, &image.img_width, &image.img_heigth);
	if (!image.img)
		ft_error("Error, Image not Found!", game);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	mlx_destroy_image(image.wlx.mlx, image.img);
	return (image.img);
}

t_block	witch_block(char name)
{
	t_block	map[6];
	int		i;

	map[0] = (t_block){"0", "./img/grass.xpm"};
	map[1] = (t_block){"1", "./img/water.xpm"};
	map[2] = (t_block){"C", "./img/plants.xpm"};
	map[3] = (t_block){"P", "./img/front.xpm"};
	map[4] = (t_block){"E", "./img/exit.xpm"};
	map[5] = (t_block){NULL, NULL};
	i = 0;
	while (map[i].name != NULL)
	{
		if (map[i].name[0] == name)
		{
			return (map[i]);
			break ;
		}
		i++;
	}
	return (map[5]);
}
