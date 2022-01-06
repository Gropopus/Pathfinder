/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:42:17 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:22:30 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_first_atoi(const char *str, int i, int *np)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*np = *np * -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		np;
	int		ret;
	long	res;

	np = 1;
	res = 0;
	ret = 1;
	i = 0;
	i = ft_first_atoi(str, i, &np);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i++] - '0');
		if (res < 0 && (np == 1 || np == -1))
		{
			if (np == 1)
				ret = -1;
			else
				ret = 0;
		}
	}
	if (ret == 1)
		return (res * np);
	else
		return (ret);
}
