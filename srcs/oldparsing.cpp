/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:07:46 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/05 20:31:34 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/pathfinder.hpp"

int	is_char_ok(char c)
{
	if (c != 'S' && c != 'E' && c != '0' && c != '1')
		return (-1);
	return (1);
}

int	is_info_ok(t_check *check)
{
	if (check->start != 1)
		return (ft_error("Map must have a single start position\n"));
	if (check->end != 1)
		return (ft_error("Map must have a single end position\n"));
	return (1);
}

int	check_info(t_dat *game, t_check *check, int i, int j)
{
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'S')
			{
				game->s_x = i;
				game->s_y = j;
				check->start++;
			}
			else if (game->map[i][j] == 'E')
			{
				check->end++;
				game->e_x = i;
				game->e_y = j;
			}
			else if (is_char_ok(game->map[i][j]) == -1)
				return (ft_error("Invalid character in map\n"));
			j++;
		}
		i++;
	}
	if (is_info_ok(check) == 0)
		return (0);
	return (1);
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
		return (1);
	else
		return (0);
}

int	read_map(int fd, t_dat *game)
{
	int		ret;
	char	buff[5000];

	ft_bzero(buff, 5000);
	while (1)
	{
		ret = read(fd, buff, 5000);
		if (ret < 0)
			return (ft_error("Map cannot be read\n"));
		if (ret == 0)
			break ;
	}
	game->map = ft_split(buff, '\n');
	if (game->map == NULL)
		return (ft_error("Failed to allocate memory for the Map\n"));
	return (1);
}

int	is_closed(t_dat *game, int i, int end)
{
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	end = ft_strlen(game->map[0]) - 1;
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (ft_error("Map is not closed\n"));
		else if (game->map[i][end] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	i = 0;
	end = ft_tab_len(game->map) - 1;
	while (game->map[end][i])
	{
		if (game->map[end][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	return (1);
}

int	is_rect(t_dat *game)
{
	int	i;

	game->raw = ft_strlen(game->map[0]);
	game->col = ft_tab_len(game->map);
	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->raw)
			return (ft_error("Map is not a rectangle\n"));
		i++;
	}
	return (1);
}

int	ft_parsing(char *arg, t_dat *game)
{
	int		fd;
	t_check	check;

	check.start = 0;
	check.end = 0;
	if (is_map(arg) == 0)
		return (ft_error("Map must end with .ber\n"));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (ft_error("Map cannot be openned\n"));
	if (read_map(fd, game) == 0)
		return (0);
	if (is_rect(game) == 0 || is_closed(game, 0, 0) == 0)
		return (0);
	if (check_info(game, &check, 0, 0) == 0)
		return (0);
	return (1);
}
