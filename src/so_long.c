/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:36:59 by biaroun           #+#    #+#             */
/*   Updated: 2023/04/11 11:51:38 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_tab(t_solong *map, char *av)
{
	int		fd;
	int		i;
	char	*tmp;

	i = -1;
	map->line_max = 0;
	map->count_line = 1;
	fd = open(av, O_DIRECTORY);
	if (fd != -1)
		file_error(1);
	else
	{
		fd = open(av, O_RDONLY);
		if (fd == -1)
			file_error(2);
	}
	tmp = ft_get_next_line(fd);
	if (tmp == 0)
		file_error(2);
	while (ft_get_next_line(fd))
		map->count_line++;
	while (tmp[++i])
		map->line_max++;
}

void	add_map(t_solong *map, char *av)
{
	int		fd;
	int		i;

	map->tab = malloc(sizeof(char *) * map->count_line + 1);
	fd = open(av, O_RDONLY);
	i = 0;
	while (i < map->count_line)
		map->tab[i++] = ft_get_next_line(fd);
	map->tab[i] = NULL;
}

void	map_init(t_solong *map)
{
	map->mlx = mlx_init();
	map->player_right = "img/among_right.xpm";
	map->player_left = "img/among_left.xpm";
	map->player_down = "img/among_front.xpm";
	map->player_up = "img/among_back.xpm";
	map->collectible = "img/collectible.xpm";
	map->ground = "img/ground.xpm";
	map->exit = "img/exit.xpm";
	map->wall = "img/wall.xpm";
	map->move = 0;
}

static void	texture_init(t_solong *map)
{
	map->win = mlx_new_window(map->mlx, map->line_max * 32,
			map->count_line * 32, "Among Game");
	map->is_collectible = mlx_xpm_file_to_image(map->mlx, map->collectible,
			&map->screen_width, &map->screen_height);
	map->is_player = mlx_xpm_file_to_image(map->mlx, map->player_down,
			&map->screen_width, &map->screen_height);
	map->is_ground = mlx_xpm_file_to_image(map->mlx, map->ground,
			&map->screen_width, &map->screen_height);
	map->is_wall = mlx_xpm_file_to_image(map->mlx, map->wall,
			&map->screen_width, &map->screen_height);
	map->is_exit = mlx_xpm_file_to_image(map->mlx, map->exit,
			&map->screen_width, &map->screen_height);
}

int	main(int ac, char **av)
{
	t_solong	map;

	map.tab = NULL;
	if (ac == 2)
	{
		check_ext(av[1]);
		add_tab(&map, av[1]);
		add_map(&map, av[1]);
		map_error(&map);
		is_solvable(&map);
		co_ex(&map);
		position_player(&map);
		map_init(&map);
		texture_init(&map);
		pars_map(&map);
		mlx_hook(map.win, 2, 1L<<0, key_assign, &map);
		mlx_hook(map.win, 17, 0, exit_game, &map);
		mlx_loop(map.mlx);
		free_tab(map.tab);
		return (0);
	}
	ft_putendl_fd("Need map.ber", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
