/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:39:16 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 19:28:19 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.hpp"
# include "../libft/libft.h"

std::string		get_file(char *file)
{
	string				content;
	std::stringstream	buffer;
	std::ifstream		infile(file);
	if (infile.fail())
		ft_error("Cannot open map");
	buffer << infile.rdbuf();
	if (buffer.fail())
		return (NULL);
	infile.close();
	content = buffer.str();
	buffer.clear();
	return (content);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (str[i] == '.' && str[i + 1] == 'm' && str[i + 2] == 'a'
		&& str[i + 3] == 'p')
		return (0);
	else
	{
		cout << RED << "Error: " << NC << "Bad extension, map neeeds to end with .map";
		return (1);
	}
}

int	is_rect(t_algo *info)
{
	int	i;

	info->row = ft_strlen(info->map[0]);
	info->col = ft_tab_len(info->map);
	i = 0;
	while (info->map[i])
	{
		if ((int)ft_strlen(info->map[i]) != info->row)
			return (ft_error("Map is not a rectangle\n"));
		i++;
	}
	return (0);
}

int	is_closed(t_algo *info, int i, int end)
{
	while (info->map[0][i])
	{
		if (info->map[0][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	end = ft_strlen(info->map[0]) - 1;
	i = 0;
	while (info->map[i])
	{
		if (info->map[i][0] != '1')
			return (ft_error("Map is not closed\n"));
		else if (info->map[i][end] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	i = 0;
	end = ft_tab_len(info->map) - 1;
	while (info->map[end][i])
	{
		if (info->map[end][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	return (0);
}

int	is_char_ok(char c)
{
	if (c != 'S' && c != 'E' && c != '0' && c != '1')
		return (-1);
	return (1);
}

int		fill_grid(t_algo *info)
{
	if ((info->grid = (int **)malloc(sizeof(int *) * info->col)) == NULL)
		return (ft_error("Cannot allocate memory"));
	info->grid[info->col] = NULL;
	int i = 0;
	while (i < info->col)
	{
		if ((info->grid[i] = (int *)malloc(sizeof(int) * info->row)) == NULL)
			return (ft_error("Cannot allocate memory"));
		i++;
	}
	i = 0;
	int j = 0;
	int nb_e = 0;
	int nb_s = 0;
	while (info->map[i])
	{
		j = 0;
		while(info->map[i][j])
		{
			if (is_char_ok(info->map[i][j]) < 0)
				return (ft_error("Invalid character in the map"));
			else if (info->map[i][j] == 'S')
			{
				nb_s++;
				info->grid[i][j] = 0;
				info->start = make_pair(i, j);
			}
			else if (info->map[i][j] == 'E')
			{
				nb_e++;
				info->grid[i][j] = 0;
				info->end = make_pair(i, j);
			}
			else
				info->grid[i][j] = info->map[i][j] - 48;
			j++;
		}
		i++;
	}
	if (nb_s != 1 || nb_e != 1)
		ft_error("The map must have only 1 start and 1 destination points.");
	return (0);
}

void	debug(t_algo *info)
{
	int i = 0;
	int j = 0;

	while (i < info->col)
	{
		j = 0;
		while (j < info->row)
		{
			cout << info->grid[i][j];
			j++;
		}
		cout << endl;
		i++;
	}
}

int		get_map(char *file, t_algo *info)
{
	if (is_map(file) > 0)
		return (-1);
	info->content = get_file(file);
	if (info->content.empty() == true)
	{
		cout << RED << "Error: " << NC << "Cannot open & read map";
		return (-1);
	}
	info->map = ft_split(info->content.c_str(), '\n');
	is_rect(info);
	is_closed(info, 0, 0);
	fill_grid(info);
//	debug(info);
	return (0);
}
