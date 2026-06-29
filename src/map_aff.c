#include "../inc/so_long.h"

typedef struct s_img_data
{
	char	*t_addr;
	char	*g_addr;
	char	*s_addr;
	int		bpp;
	int		line;
	int		endian;
	int		sbpp;
	int		sline;
	int		sendian;
	int		gbpp;
	int		gline;
	int		gendian;
}	t_img_data;

static void	copy_pixels(t_img_data d, unsigned int trans)
{
	int				x;
	int				y;
	unsigned int	col;

	y = -1;
	while (++y < PXL)
	{
		x = -1;
		while (++x < PXL)
		{
			col = *(unsigned int *)(d.s_addr + (y * d.sline + x * (d.sbpp / 8)));
			if (col == trans)
			{
				*(unsigned int *)(d.t_addr + (y * d.line + x * (d.bpp / 8))) =
					*(unsigned int *)(d.g_addr + (y * d.gline
							+ x * (d.gbpp / 8)));
			}
			else
			{
				*(unsigned int *)(d.t_addr + (y * d.line + x * (d.bpp / 8))) =
					col;
			}
		}
	}
}

static void	put_img_to_window_trans(t_solong *map, void *sprite, int wx, int wy)
{
	void		*temp;
	t_img_data	d;

	temp = mlx_new_image(map->mlx, PXL, PXL);
	if (!temp)
		return ;
	d.t_addr = mlx_get_data_addr(temp, &d.bpp, &d.line, &d.endian);
	d.g_addr = mlx_get_data_addr(map->is_ground, &d.gbpp, &d.gline, &d.gendian);
	d.s_addr = mlx_get_data_addr(sprite, &d.sbpp, &d.sline, &d.sendian);
	copy_pixels(d, *(unsigned int *)d.s_addr);
	mlx_put_image_to_window(map->mlx, map->win, temp, wx, wy);
	mlx_destroy_image(map->mlx, temp);
}

void	pars_map(t_solong *map)
{
	int	y;
	int	x;

	y = -1;
	map->y = 0;
	while (map->tab[++y])
	{
		x = -1;
		map->x = 0;
		while (map->tab[y][++x])
		{
			aff_map(map, y, x);
			map->x += PXL;
		}
		map->y += PXL;
	}
	put_img_to_window_trans(map, map->is_exit, map->exit_x, map->exit_y);
	put_img_to_window_trans(map, map->is_player, map->p_x, map->p_y);
	if (map->tab[map->exit_y / PXL][map->exit_x / PXL] != 'P')
		map->tab[map->exit_y / PXL][map->exit_x / PXL] = 'E';
}

void	aff_map(t_solong *map, int y, int x)
{
	if (map->tab[y][x] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_wall, map->x, map->y);
	}
	else if (map->tab[y][x] == '0')
		aff_ground(map);
	else if (map->tab[y][x] == 'P')
	{
		aff_ground(map);
		map->p_x = x * PXL;
		map->p_y = y * PXL;
	}
	else if (map->tab[y][x] == 'C')
	{
		aff_ground(map);
		put_img_to_window_trans(map, map->is_collectible, map->x, map->y);
	}
	else if (map->tab[y][x] == 'E')
	{
		aff_ground(map);
		put_img_to_window_trans(map, map->is_exit, map->x, map->y);
	}
}

void	aff_ground(t_solong *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->is_ground, map->x, map->y);
}

void	return_error(int c, t_solong *map)
{
	if (c == 1)
	{
		free(map->tab);
		ft_putendl_fd("player not found or too many players", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		free(map->tab);
		ft_putendl_fd("Need 1 exit and collectible !", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
