/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:06:38 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/11 19:28:32 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.h"

t_stop			*find_path_2(b_data *data, t_stop *stops, t_road *routes, int *i, int j)
{
		if (data->o_len > 0)
		{
			while (j < data->o_len)
			{
				if (routes[stops[data->current].n[*i]].y == data->open[j])
					data->b = 0;
				j++;
			}
		}
		if (data->b || (data->tmp < stops[routes[stops[data->current].n[*i]].y].g))
		{
			stops[routes[stops[data->current].n[*i]].y].from = data->current;
			stops[routes[stops[data->current].n[*i]].y].g = data->tmp;
			stops[routes[stops[data->current].n[*i]].y].f =
			stops[routes[stops[data->current].n[*i]].y].g
			+ stops[routes[stops[data->current].n[*i]].y].h;
			if (data->b)
			{
				++data->o_len;
				data->open = (int*)realloc(data->open, data->o_len * sizeof(int));
				data->open[data->o_len - 1] = routes[stops[data->current].n[*i]].y;
			}
		}
	return (stops);
}

t_stop			*find_path(b_data *data, t_stop *stops, t_road *routes)
{
	int i;
	int j;

	for (i = 0; i < stops[data->current].n_len; i++)
	{
		data->b = 0;
		j = 0;
		while (j < data->c_len)
		{
			if (routes[stops[data->current].n[i]].y == data->closed[j])
				data->b = 1;
			j++;
		}
		if (data->b)
			continue;
		data->tmp = stops[data->current].g + routes[stops[data->current].n[i]].d;
		data->b = 1;
		stops = find_path_2(data, stops, routes, &i, j);
	}
	return (stops);
}

void			open_to_path(b_data *data, t_stop *stops)
{
	int i;

	i = 0;
	while (i < data->o_len)
	{
		if (stops[data->open[i]].f < data->min)
		{
			data->current = data->open[i];
			data->min = stops[data->open[i]].f;
		}
		i++;
	}
	if (data->current == data->e)
	{
		data->found = 1;
		++data->p_len;
		data->path = (int*)realloc(data->path, data->p_len * sizeof(int));
		data->path[data->p_len - 1] = data->current;
		while (stops[data->current].from >= 0)
		{
			data->current = stops[data->current].from;
			++data->p_len;
			data->path = (int*)realloc(data->path, data->p_len * sizeof(int));
			data->path[data->p_len - 1] = data->current;
		}
	}
}

void			realloc_open(b_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->o_len)
	{
		if (data->open[i] == data->current)
		{
			if (i != (data->o_len - 1))
			{
				j = i;
				while (j < (data->o_len - 1))
				{
					data->open[j] = data->open[j + 1];
					j++;
				}
			}
			--data->o_len;
			data->open = (int*)realloc(data->open, data->o_len * sizeof(int));
			break;
		}
			i++;
	}
}
