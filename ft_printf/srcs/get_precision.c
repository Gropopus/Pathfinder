/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:56:15 by thsembel          #+#    #+#             */
/*   Updated: 2020/12/02 11:58:10 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_precision(t_data *data, char *str, int i)
{
	while (str && str[i] && str[i - 1] != '.')
		++i;
	while (str[i])
	{
		data->precision = 0;
		while (str && str[i] >= '0' && str[i] <= '9')
		{
			data->precision *= 10;
			data->precision += str[i++] - '0';
		}
		while (str && str[i++] == '*')
		{
			data->precision = va_arg(data->args, int);
			if (data->precision < 0)
			{
				data->precision = 0;
				data->b_precision = 0;
			}
		}
	}
	return (1);
}
