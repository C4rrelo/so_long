/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:45:55 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/05/05 21:37:33 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	img;

	img.path = "./img/grass.xpm";
	img.wlx = *game;
	put_img(game, img, game->player.x, game->player.y);
	put_img(game, img, x, y);
}

void	ft_up(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/front.xpm";
	img.wlx = *game;
	i = game->player.y - 64;
	j = game->player.x;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(game, img, j, i);
		ft_printf("Moves: %d\n", game->player.move);
	}
}

void	ft_down(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/down.xpm";
	img.wlx = *game;
	i = game->player.y + 64;
	j = game->player.x;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(game, img, j, i);
		ft_printf("Moves: %d\n", game->player.move);
	}
}

void	ft_left(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/left.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x - 64;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(game, img, j, i);
		ft_printf("Moves: %d\n", game->player.move);
	}
}

void	ft_right(t_game *game)
{
	int		i;
	int		j;
	t_image	img;

	img.path = "./img/right.xpm";
	img.wlx = *game;
	i = game->player.y;
	j = game->player.x + 64;
	if ((check_move(game, (i / 64), (j / 64)) != 1))
	{
		game->player.move++;
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_img(game, img, j, i);
		ft_printf("Moves: %d\n", game->player.move);
	}
}
