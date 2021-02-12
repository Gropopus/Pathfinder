/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:20:29 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/12 21:16:45 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.h"

void		init_targets(b_data *data, char **map)
{
	int i;
	int j;
	int zero;
 (void)data;
	i = 0;
	zero = 0;
	while (i < data->size_cols)
	{
		j = 0;
		while (j < data->size_rows)
		{
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'E')
			{
				zero++;
				if (map[i][j] == 'S')
					data->s = zero - 1;
				else if (map[i][j] == 'E')
					data->e = zero - 1;
			}
			j++;
		}
		i++;
	}
	printf("zero = %d start = %d end = %d\n", zero, data->s, data->e);
}

int			**init_ind(b_data *data, int **ind)
{
	int i;
	int j;

	i = 0;
	if ((ind = malloc(sizeof(int *) * (data->size_cols))) == NULL)
		return (NULL);
	ind[data->size_cols] = NULL;
	while (i < data->size_cols)
	{
		if ((ind[i] = malloc(sizeof(int) * (data->size_rows))) == NULL)
			return (NULL);
		ind[i][data->size_rows] = 0;
		j = 0;
		while (j < data->size_rows)
		{
			ind[i][j] = -1;
			j++;
		}
		i++;
	}
	return (ind);
}

t_stop		*set_stops(b_data *data, t_stop *stops)
{
	int i;
	
	i = 0;
	while (i < data->s_len)
	{
		stops[i].h = sqrt(pow(stops[data->e].row - stops[i].row, 2)
		+ pow(stops[data->e].col - stops[i].col, 2));
		i++;
	}
	return (stops);
}

t_stop		*init_stops(b_data *data, t_stop *stops, char **map, int **ind)
{
	int t;
	int i;
	int j;
	i = 1;
	while (i < data->size_cols - 1)
	{
		j = 1;
		while (j < data->size_rows - 1)
		{
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'E')
			{
				++data->s_len;
				stops = (t_stop *)realloc(stops, data->s_len * sizeof(t_stop));
				t = data->s_len - 1;
				stops[t].col = j;
				stops[t].row = i;
				stops[t].from = -1;
				stops[t].g = DBL_MAX;
				stops[t].n_len = 0;
				stops[t].n = NULL;
				ind[i][j] = t;
			}
			j++;
		}
		i++;
	}
	return (stops);
}

void		init_data(b_data *data)
{
	data->c_len = 0;
	data->o_len = 1;
	data->found = 0;
	data->p_len = 0;
	data->r_len = 0;
	data->s = 0;
	data->e = 0;
	data->s_len = 0;
	data->path = NULL;
	data->closed = NULL;
	data->open = (int*)calloc(1, sizeof(int));
}
