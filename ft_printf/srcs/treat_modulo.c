/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_modulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:34:55 by thsembel          #+#    #+#             */
/*   Updated: 2020/12/02 12:00:27 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_is_minus(t_data *data)
{
	int	len;

	len = 1;
	ft_buffcpy(data, "%");
	while (len < data->width)
	{
		ft_buffcpy(data, " ");
		len++;
	}
}

void			ft_treat_modulo(t_data *data)
{
	int	len;

	len = 1;
	if (data->b_minus)
	{
		ft_is_minus(data);
		return ;
	}
	if (data->b_width)
	{
		while (len < data->width)
		{
			if (data->b_zero)
				ft_buffcpy(data, "0");
			else
				ft_buffcpy(data, " ");
			len++;
		}
	}
	ft_buffcpy(data, "%");
}
