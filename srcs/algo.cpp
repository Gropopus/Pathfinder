/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:36:51 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 18:51:59 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pathfinder.hpp"

bool isInRange(int row, int col, t_algo *info)
{
	return (row >= 0) && (row < info->row) && (col >= 0) && (col < info->col);
}

bool isWall(int **grid, int row, int col)
{
	if (grid[col][row] == 0)
		return (true);
	return (false);
}

bool isEnd(int row, int col, Pair end)
{
	if (row == end.second && col == end.first)
		return (true);
	return (false);
}

// calculate the heuristic -> h
double calculateHValue(int row, int col, Pair end)
{
	return ((double)sqrt((row - end.second) * (row - end.second)
	+ (col - end.first) * (col - end.first)));
}

void	StockPath(cell **cellDetails, Pair end, t_algo *info)
{
	int			row = end.second;
	int			col = end.first;

	while (!(cellDetails[col][row].parent_i == col
		&& cellDetails[col][row].parent_j == row))
	{
		info->path.push(make_pair(col, row));
		int	temp_row = cellDetails[col][row].parent_j;
		int	temp_col = cellDetails[col][row].parent_i;
		row = temp_row;
		col = temp_col;
	}
	info->path.push(make_pair(col, row));
	return;
}

void aStarSearch(int **grid, Pair start, Pair end, t_algo *info, int diagonal)
{
	bool	**closedList;
	cell	**cellDetails;
	int		i = 0;
	int		j = 0;

	info->arrived = false;
	cellDetails = (cell **)malloc(sizeof(cell *) * info->col);
	closedList = (bool **)malloc(sizeof(bool*) * info->col);
	while (i < info->col)
	{
		closedList[i] = (bool*)malloc(sizeof(bool) * info->row);
		cellDetails[i] = (cell*)malloc(sizeof(cell) * info->row);
		j = 0;
		while (j < info->row)
		{
			closedList[i][j] = false;
			j++;
		}
		i++;
	}
	for (i = 0; i < info->col; i++)
	{
		for (j = 0; j < info->row; j++)
		{
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}
	i = start.first, j = start.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;
	set<pPair> openList;
	openList.insert(make_pair(0.0, make_pair(i, j)));
	while (!openList.empty())
	{
		pPair p = *openList.begin();
		openList.erase(openList.begin());
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		double gNew = 0, hNew = 0, fNew = 0;
		//----------- North ------------//
		if (isInRange(j, i - 1, info) == true)
		{
			if (isEnd(j, i - 1, end) == true)
			{
				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
				StockPath(cellDetails, end, info);
				info->arrived = true;
				return;
			}
			else if (closedList[i - 1][j] == false && isWall(grid, j, i - 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(j, i - 1, end);
				fNew = gNew + hNew;
				if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew)
				{
					openList.insert(make_pair(
					fNew, make_pair(i - 1, j)));
					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
				}
			}
		}
		//----------- South ------------//
		if (isInRange(j, i + 1, info) == true)
		{
			if (isEnd(j, i + 1, end) == true)
			{
				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
				StockPath(cellDetails, end, info);
				info->arrived = true;
				return;
			}
			else if (closedList[i + 1][j] == false && isWall(grid, j, i + 1) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(j, i + 1, end);
				fNew = gNew + hNew;
				if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew)
				{
					openList.insert(make_pair(
					fNew, make_pair(i + 1, j)));
					cellDetails[i + 1][j].f = fNew;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
				}
			}
		}
		//----------- East ------------//
		if (isInRange(j + 1, i, info) == true)
		{
			if (isEnd(j + 1, i, end) == true)
			{
				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
				StockPath(cellDetails, end, info);
				info->arrived = true;
				return;
			}
			else if (closedList[i][j + 1] == false && isWall(grid, j + 1, i) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(j + 1, i, end);
				fNew = gNew + hNew;
				if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew)
				{
					openList.insert(make_pair(
					fNew, make_pair(i, j + 1)));
					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
				}
			}
		}
		//----------- West ------------//
		if (isInRange(j - 1, i, info) == true)
		{
			if (isEnd(j - 1, i, end) == true)
			{
				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
				StockPath(cellDetails, end, info);
				info->arrived = true;
				return;
			}
			else if (closedList[i][j - 1] == false && isWall(grid, j - 1, i) == true)
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(j - 1, i, end);
				fNew = gNew + hNew;
				if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew)
				{
					openList.insert(make_pair(
					fNew, make_pair(i, j - 1)));
					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;
				}
			}
		}
		if (diagonal == 1)
		{
			//----------- North-East -----------//
			if (isInRange(j + 1, i - 1, info) == true)
			{
				if (isEnd(j + 1, i - 1, end) == true)
				{
					cellDetails[i - 1][j + 1].parent_i = i;
					cellDetails[i - 1][j + 1].parent_j = j;
					StockPath(cellDetails, end, info);
					info->arrived = true;
					return;
				}
				else if (closedList[i - 1][j + 1] == false && isWall(grid, j + 1, i - 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(j + 1, i - 1, end);
					fNew = gNew + hNew;
					if (cellDetails[i - 1][j + 1].f == FLT_MAX || cellDetails[i - 1][j + 1].f > fNew)
					{
						openList.insert(make_pair(
									fNew, make_pair(i - 1, j + 1)));
						cellDetails[i - 1][j + 1].f = fNew;
						cellDetails[i - 1][j + 1].g = gNew;
						cellDetails[i - 1][j + 1].h = hNew;
						cellDetails[i - 1][j + 1].parent_i = i;
						cellDetails[i - 1][j + 1].parent_j = j;
					}
				}
			}
			//----------- North-West -----------//
			if (isInRange(j - 1, i - 1, info) == true)
			{
				if (isEnd(j - 1, i - 1, end) == true)
				{
					cellDetails[i - 1][j - 1].parent_i = i;
					cellDetails[i - 1][j - 1].parent_j = j;
					StockPath(cellDetails, end, info);
					info->arrived = true;
					return;
				}
				else if (closedList[i - 1][j - 1] == false && isWall(grid, j - 1, i - 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(j - 1, i - 1, end);
					fNew = gNew + hNew;
					if (cellDetails[i - 1][j - 1].f == FLT_MAX || cellDetails[i - 1][j - 1].f > fNew)
					{
						openList.insert(make_pair(
									fNew, make_pair(i - 1, j - 1)));
						cellDetails[i - 1][j - 1].f = fNew;
						cellDetails[i - 1][j - 1].g = gNew;
						cellDetails[i - 1][j - 1].h = hNew;
						cellDetails[i - 1][j - 1].parent_i = i;
						cellDetails[i - 1][j - 1].parent_j = j;
					}
				}
			}
			//----------- South-East ------------//
			if (isInRange(j + 1, i + 1, info) == true)
			{
				if (isEnd(j + 1, i + 1, end) == true)
				{
					cellDetails[i + 1][j + 1].parent_i = i;
					cellDetails[i + 1][j + 1].parent_j = j;
					StockPath(cellDetails, end, info);
					info->arrived = true;
					return;
				}
				else if (closedList[i + 1][j + 1] == false && isWall(grid, j + 1, i + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(j + 1, i + 1, end);
					fNew = gNew + hNew;
					if (cellDetails[i + 1][j + 1].f == FLT_MAX || cellDetails[i + 1][j + 1].f > fNew)
					{
						openList.insert(make_pair(
									fNew, make_pair(i + 1, j + 1)));
						cellDetails[i + 1][j + 1].f = fNew;
						cellDetails[i + 1][j + 1].g = gNew;
						cellDetails[i + 1][j + 1].h = hNew;
						cellDetails[i + 1][j + 1].parent_i = i;
						cellDetails[i + 1][j + 1].parent_j = j;
					}
				}
			}
			//----------- South-West ------------//
			if (isInRange(j - 1, i + 1, info) == true)
			{
				if (isEnd(j - 1, i + 1, end) == true)
				{
					cellDetails[i + 1][j - 1].parent_i = i;
					cellDetails[i + 1][j - 1].parent_j = j;
					StockPath(cellDetails, end, info);
					info->arrived = true;
					return;
				}
				else if (closedList[i + 1][j - 1] == false && isWall(grid, j - 1, i + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(j - 1, i + 1, end);
					fNew = gNew + hNew;
					if (cellDetails[i + 1][j - 1].f == FLT_MAX || cellDetails[i + 1][j - 1].f > fNew)
					{
						openList.insert(make_pair(
									fNew, make_pair(i + 1, j - 1)));
						cellDetails[i + 1][j - 1].f = fNew;
						cellDetails[i + 1][j - 1].g = gNew;
						cellDetails[i + 1][j - 1].h = hNew;
						cellDetails[i + 1][j - 1].parent_i = i;
						cellDetails[i + 1][j - 1].parent_j = j;
					}
				}
			}
		}
	}
	i = 0;
	while (i < info->col)
	{
		free(cellDetails[i]);
		free(closedList[i]);
		free(info->grid[i]);
		i++;
	}
	free(cellDetails);
	free(closedList);
	free(info->grid);
	if (info->arrived == false)
		ft_error("Failed to reach the Destination.\n");
	return;
}
