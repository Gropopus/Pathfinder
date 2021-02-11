/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:20:29 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/11 23:47:37 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.h"

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
	data->e = data->s_len -1;
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
			if (map[i][j] == '0')
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
	data->s_len = 0;
	data->path = NULL;
	data->closed = NULL;
	data->open = (int*)calloc(1, sizeof(int));
}
