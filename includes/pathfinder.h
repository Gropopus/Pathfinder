/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:49:35 by thsembel          #+#    #+#             */
/*   Updated: 2021/02/12 19:01:56 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PATHFINDER_H
#define PATHFINDER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <float.h>
# include <iso646.h>
# include <math.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_stop
{
    int		from;
	int		*n;
    int		n_len;
	double	col;
	double	row;
    double	f;
	double	g;
	double	h;
}				t_stop;

typedef struct	s_road {
    /* route has only one direction! */
    int		x; /* index of stop in array of all stops of src of this route */
    int		y; /* intex of stop in array of all stops od dst of this route */
    double	d;
}				t_road;

typedef struct	a_data
{
	char	map[100][100];
	int		ind[500][500];
	int		b;
	int		current;
	int		o_len;
	int		c_len;
	int		found;
	int		p_len;
	int		r_len;
	int		s;
	int		e;
	int		s_len;
	int		size_rows;
	int		size_cols;
	int		*path;
	int		*closed;
	int		*open;
	double	min;
	double	tmp;
}				b_data;

int				**init_ind(b_data *data, int **ind);
t_stop			*init_stops(b_data *data, t_stop *stops, char **map, int **ind);
t_stop			*set_stops(b_data *data, t_stop *stops);
void			init_targets(b_data *data, char **map);
void			init_data(b_data *data);
void			display_result(b_data *data, char **map, int **ind);
void			display_path(b_data *data, t_stop *stops);
void			realloc_open(b_data *data);
void			open_to_path(b_data *data, t_stop *stops);
t_stop			*find_path(b_data *data, t_stop *stops, t_road *routes);

# endif
