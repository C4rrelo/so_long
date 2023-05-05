/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:46:45 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/05/05 21:42:24 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	control_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exitcheck++;
			j++;
		}
		i++;
	}
	if (game->exitcheck != 1)
		ft_error("Error\n", game);
	if (game->coincheck == 0)
		ft_error("Error\n", game);
	if (game->playercheck != 1)
		ft_error("Error\n", game);
}

void	control_wall(t_game *game)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < (game->size_y / 64))
	{
		x = 0;
		while (x < (game->size_x / 64))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				ft_error("Error\n", game);
			else if ((y == (game->size_y / 64)
					|| x == (game->size_x / 64))
				&& game->map[y][x] != '1')
				ft_error("Error\n", game);
			x++;
		}
		y++;
	}
}

void	control_game(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->coincheck++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * 64;
				game->player.y = i * 64;
				game->playercheck++;
			}
			j++;
		}
		i++;
	}
	control_map(game);
	control_wall(game);
	fill_flood(game);
}

int	check_move(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C' || game->map[i][j] == 'D')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
			return (1);
		window_destroy(game);
	}
	return (0);
}
