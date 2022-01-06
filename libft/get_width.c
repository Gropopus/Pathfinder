/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:14:41 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 14:19:16 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_width(t_data *data, char *str, int i)
{
	while (str && str[i] && (str[i] <= '0' || str[i] > '9') && str[i] != '.'
		&& str[i] != '*')
		++i;
	while (str[i] && str[i] != '.')
	{
		while (str && (str[i] >= '0' && str[i] <= '9'))
		{
			data->width *= 10;
			data->width += str[i] - '0';
			++i;
		}
		while (str && str[i] == '*')
		{
			data->width = va_arg(data->args, int);
			if (data->width < 0)
			{
				data->b_minus = 1;
				data->width *= (-1);
			}
			++i;
		}
	}
	return (1);
}
