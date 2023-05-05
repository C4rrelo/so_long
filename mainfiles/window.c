/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:45:40 by tmiguel-          #+#    #+#             */
/*   Updated: 2023/03/29 12:45:40 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_game *data, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error File");
		exit(1);
	}
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
	{
		ft_printf("Error File");
		exit(1);
	}
	data->size_x = (ft_line(fd) * 64);
	data->size_y = (ft_count_line(fd) * 64);
	if (data->size_y == 0 || data->size_x == 0)
	{
		ft_printf("Empty map!\n");
		exit(1);
	}
	else if (data->size_x == (long unsigned int)data->size_y)
	{
		ft_printf("Square Map!");
		exit(1);
	}
}

int	window_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	destroy_map(game);
	free(game->mlx);
	exit(0);
}

void	flood_fill(int x, int y, int *flag, char **tab)
{
	if (tab[y][x] == '1' || tab[y][x] == 'P' || tab[y][x] == 'D')
		return ;
	else if (tab[y][x] == '0')
		tab[y][x] = 'P';
	else if (tab[y][x] == 'C')
		tab[y][x] = 'D';
	else if (tab[y][x] == 'E')
	{
		(*flag)++;
		tab[y][x] = 'E';
	}
	flood_fill(x + 1, y, flag, tab);
	flood_fill(x - 1, y, flag, tab);
	flood_fill(x, y + 1, flag, tab);
	flood_fill(x, y - 1, flag, tab);
}

int	check_all_collectible(char **tab)
{
	int	x;
	int	y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	fill_flood(t_game *game)
{
	int		x;
	int		y;
	int		flag;
	char	**tab;

	flag = 0;
	x = game->player.x;
	y = game->player.y;
	tab = game->map;
	flood_fill(x / 64 + 1, y / 64, &flag, tab);
	flood_fill(x / 64 - 1, y / 64, &flag, tab);
	flood_fill(x / 64, y / 64 - 1, &flag, tab);
	flood_fill(x / 64, y / 64 + 1, &flag, tab);
	if (flag == 0 || !check_all_collectible(tab))
		ft_error("Exit Error\n", game);
}
