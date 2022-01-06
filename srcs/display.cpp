/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:05:49 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 18:50:21 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.hpp"

void	display_pc(t_display *window, t_algo *info, int i, int j)
{
	if (info->map[i][j] == 'x')
	{
		mlx_put_image_to_window(window->mlx, window->win, window->img[2],
			j * 32, i * 32);
	}
	if (info->map[i][j] == 'S')
		mlx_put_image_to_window(window->mlx, window->win, window->img[0],
			j * 32, i * 32);
}

void	draw_map(t_display *window, t_algo *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->col)
	{
		j = 0;
		while (j < info->row)
		{
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(window->mlx, window->win, window->img[4],
					j * 32, i * 32);
			else if (info->map[i][j] == 'E')
			{
				mlx_put_image_to_window(window->mlx, window->win, window->img[1],
					j * 32, i * 32);
			}
			else if (info->map[i][j] != '1')
				mlx_put_image_to_window(window->mlx, window->win, window->img[3],
					j * 32, i * 32);
			display_pc(window, info, i, j);
			j++;
		}
		i++;
	}
}

int	load_assets(t_display *window)
{
	int		i;
	char	**path;

	path = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		window->img[i] = mlx_xpm_file_to_image(window->mlx, path[i],
				&window->x[i], &window->y[i]);
		if (!window->img[i])
		{
			ft_free_tab(path);
			return (ft_error("Cannot load player texture\n"));
		}
		i++;
	}
	ft_free_tab(path);
	return (1);
}

void	handleSignals(int sig)
{
	std::cout << "\b  ";
	std::cout << std::endl << RED << "Exiting..." << NC << std::endl;
	if (SIGINT == sig)
		exit(0);
}

void	display(t_algo *info, t_display *window)
{
	window->mlx = mlx_init();
	load_assets(window);
	window->res_y = (int)(info->col * window->y[4]);
	window->res_x = (int)(info->row * window->x[4]);
	window->win = mlx_new_window(window->mlx, window->res_x, window->res_y, "Pathfinder");
	draw_map(window, info);
	ft_free_tab(info->map);
	signal(SIGINT, handleSignals);
	mlx_loop(window->mlx);
}
