/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:48:14 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/05 22:27:58 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.hpp"

t_dat game;

int	ft_error(std::string str)
{
	std::cout << RED << "Error: " << NC << str;
	return (0);
}

int	exit_game(void)
{
	ft_free_tab(game.map);
	if (game.win)
		mlx_destroy_window(game.mlx, game.win);
	if (game.mlx)
		free(game.mlx);
	exit(0);
}

int	esc_game(void)
{
	exit_game();
	exit(0);
	return (1);
}

int	load_assets(t_dat game)
{
	int		i;
	char	**path;

	path = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		game.text.img[i] = mlx_xpm_file_to_image(game.mlx, path[i],
				&game.text.x[i], &game.text.y[i]);
		if (!game.text.img[i])
		{
			ft_free_tab(path);
			return (ft_error("Cannot load player texture\n"));
		}
		i++;
	}
	ft_free_tab(path);
	return (1);
}


void	display_map(t_dat game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.col)
	{
		j = 0;
		while (j < game.raw)
		{
			if (game.map[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.text.img[4],
					j * 32, i * 32);
			else if (game.map[i][j] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.text.img[1],
					j * 32, i * 32);
			}
			else if (game.map[i][j] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.text.img[3],
					j * 32, i * 32);
			else if (game.map[i][j] == 'S')
				mlx_put_image_to_window(game.mlx, game.win, game.text.img[0],
					game.s_y * 32, game.s_x * 32);
			j++;
		}
		i++;
	}
}


int	play(void)
{
	display_map(game);
	return (1);
}

void	start_game(t_dat game)
{
	game.res_y = (int)(game.col * game.text.y[4]);
	game.res_x = (int)(game.raw * game.text.x[4]);
	game.win = mlx_new_window(game.mlx, game.res_x, game.res_y, "Pathfinder");
//	mlx_hook(game.win, 33, 1L << 5, esc_game, NULL);
	mlx_loop_hook(game.mlx, play, NULL);
	mlx_loop(game.mlx);
}

int		main(int ac, char **av)
{
	//t_dat game;

	if (ac != 2)
		return (ft_error("Wrong number of argument.\nUsage: ./pathfinder file.map\n"));
	if (ft_parsing(av[1], &game) == 0)
	{
		ft_free_tab(game.map);
		return (0);
	}
	game.mlx = mlx_init();
	if (load_assets(game) == 0)
		return (exit_game());
	start_game(game);
	return (0);
}
