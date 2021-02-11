/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:34:56 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/11 23:58:09 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/pathfinder.h"
# include "../includes/libft.h"
# include "../includes/get_next_line.h"
# include "../includes/ft_printf.h"

int		ft_strrlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		**ft_open_file(b_data *data, char *file, char **map)
{
	int fd;
	int ret;
	int line;
	char buff[1001];

	line = 0;
	ft_bzero(buff, '\0');
	if ((fd = open(file, O_RDONLY)) < 0 || (read(fd, buff, 1000)) < 0)
		return (NULL);
	while ((ret = read(fd, buff, 1000)) > 0)
		buff[ret] = '\0';
	ret = 0;
	while (buff[ret])
	{
		if (buff[ret] == '\n')
			line++;
		ret++;
	}
	data->size_cols = line;
	ret = 0;
	if ((map = malloc(sizeof(char *) * (line))) == NULL)
		return (NULL);
	map[line] = NULL;
	close (fd);
	fd = open(file, O_RDONLY);
	while (ret < line)
	{
		get_next_line(fd, &map[ret]);
		ret++;
	}
	data->size_rows = ft_strrlen(map[0]);
	close (fd);
	return (map);
}

int				ft_free_exit(b_data *data, t_stop *stops, t_road *routes)
{
	int i;

	i = 0;
	while  (i < data->s_len)
	{
		free(stops[i].n);
		i++;
	}
	free(stops);
	free(routes);
	free(data->path);
	free(data->open);
	free(data->closed);
	return (0);
}

int				main(int ac, char **av)
{
	int			i, j, k, l, t;
	t_stop		*stops = NULL;
	t_road		*routes = NULL;
	char		**map = NULL;
	int			**ind = NULL;
	b_data data;

	if (ac != 2)
		return (0);
	if ((map = ft_open_file(&data, av[1], map)) == NULL)
		return (0);
	init_data(&data);
	ind = init_ind(&data, ind);
	stops = init_stops(&data, stops, map, ind);
	stops = set_stops(&data, stops);
	i = 1;
	while (i < data.size_rows - 1)
	{
		j = 1;
		while (j < data.size_cols - 1)
		{
			if (ind[i][j] >= 0)
			{
				k = i - 1;
				while (k <= i + 1)
				{
					l = j - 1;
					while (l <= j + 1)
					{
						if (ind[k][l] >= 0)
						{
							++data.r_len;
							routes = (t_road *)realloc(routes, data.r_len * sizeof(t_road));
							t = data.r_len - 1;
							routes[t].x = ind[i][j];
							routes[t].y = ind[k][l];
							routes[t].d = sqrt(pow(stops[routes[t].y].row - stops[routes[t].x].row, 2)
							+ pow(stops[routes[t].y].col - stops[routes[t].x].col, 2));
							++stops[routes[t].x].n_len;
							stops[routes[t].x].n = (int*)realloc(stops[routes[t].x].n, stops[routes[t].x].n_len * sizeof(int));
							stops[routes[t].x].n[stops[routes[t].x].n_len - 1] = t;
						}
						l++;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	data.open[0] = data.s;
	stops[data.s].g = 0;
	stops[data.s].f = stops[data.s].g + stops[data.s].h;
	data.found = 0;
	while (data.o_len && !data.found)
	{
		data.min = DBL_MAX;
		open_to_path(&data, stops);
		realloc_open(&data);
		++data.c_len;
		data.closed = (int*)realloc(data.closed, data.c_len * sizeof(int));
		data.closed[data.c_len - 1] = data.current;
		stops = find_path(&data, stops, routes);
	}
	display_result(&data, map, ind);
	display_path(&data, stops);
	return (ft_free_exit(&data, stops, routes));
}
