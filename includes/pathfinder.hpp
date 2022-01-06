/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:45:06 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 18:48:26 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PATHFINDER_HPP
# define PATHFINDER_HPP

#include <fstream>
#include <sstream>
#include <cfloat>
#include <stack>
#include <set>
#include <math.h>
#include <iostream>
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN   "\033[0;36m"
# define NC     "\033[0m"
# define PATH "./text/p.xpm ./text/e.xpm ./text/c.xpm ./text/f.xpm ./text/w.xpm"
//# define KEY_EXIT_HOOK		53
extern "C"
{
	#include <signal.h>
	#include <stdlib.h>
	#include "../libft/libft.h"
	#include "../mlx_lib/mlx.h"
}

using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int> > pPair;

typedef struct	s_algo
{
	Pair		start;
	Pair		end;
	stack<Pair>	path;
	int			**grid;
	int			col;
	int			row;
	bool		arrived;
	char		**map;
	string		content;
}				t_algo;

struct			cell
{
	int			parent_i;
	int			parent_j;
    double		f;
	double		g;
	double		h;
};

typedef	struct	s_display
{
	void		*img[5];
	int			x[5];
	int			y[5];
	int			res_x;
	int			res_y;
	void		*mlx;
	void		*win;
}				t_display;

int		ft_error(string error);
int		get_map(char *file, t_algo *info);
void	aStarSearch(int **grid, Pair start, Pair end, t_algo *info, int diagonal);
void	display(t_algo *info, t_display *window);
# endif
