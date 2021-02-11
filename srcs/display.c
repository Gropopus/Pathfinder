/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:13:52 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/11 22:19:10 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.h"

void			display_path(b_data *data, t_stop *stops)
{
	int i;

	i = 0;
	if (!data->found)
		 printf("IMPOSSIBLE");
	else
	{
		printf("path cost is %d:\n", data->p_len);
		i = data->p_len - 1;
		while (i >= 0)
		{
			printf("(%1.0f, %1.0f)\n", stops[data->path[i]].col, stops[data->path[i]].row);
			i--;
		}
	}
}

void			display_result(b_data *data, char **map, int **ind/*[10][10]*/)
{
	int i;
	int j;
	int k;
	int b;

	i = 0;
	while (i < data->size_cols)
	{
		j = 0;
		while (j < data->size_rows)
		{
			if (map[i][j] == '1')
				putchar('1');
			else
			{
				b = 0;
				k = 0;
				while (k < data->p_len)
				{
					if (ind[i][j] == data->path[k])
						++b;
					k++;
				}
				if (b)
					putchar('x');
				else
					putchar('.');
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
