/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:33:55 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 18:31:41 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pathfinder.hpp"

int		ft_error(std::string error)
{
	cout << RED << "Error: " << NC << error << endl;
	exit(1);
}

void	write_path(t_algo *info)
{
	while (!info->path.empty())
	{
		pair<int, int> p = info->path.top();
		info->path.pop();
		if (info->map[p.first][p.second] != 'S' && info->map[p.first][p.second] != 'E')
			info->map[p.first][p.second] = 'x';
	}
	int i = 0;
	while (info->map[i])
	{
		cout << info->map[i] << endl;
		i++;
	}
}

int		main(int ac, char **av)
{
	t_algo		info;
	t_display	window;
	if (ac < 2 || ac > 3)
		return (ft_error("Wrong number of argument.\nUsage: ./Pathfinder [optional -d] [file.map]"));
	if (ac == 2)
	{
		if (get_map(av[1], &info) == 1)
			return (1);
	}
	else
	{
		if (get_map(av[2], &info) == 1)
			return (1);
	}
	if (ac == 3 && ft_strcmp(av[1], "-d") == 0)
		aStarSearch(info.grid, info.start, info.end, &info, 1);
	else
		aStarSearch(info.grid, info.start, info.end, &info, 0);
	write_path(&info);
	display(&info, &window);
	return (0);
}
