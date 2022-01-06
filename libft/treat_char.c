/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:56:42 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 14:22:07 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_space(t_data *data, char c)
{
	int	i;

	i = 0;
	while (i < data->width - 1)
	{
		write(1, &c, 1);
		++data->return_val;
		++i;
	}
}

int	ft_treat_char(t_data *data)
{
	char	c;
	char	space;

	data->flag_c0 = 0;
	space = ' ';
	c = (char)va_arg(data->args, int);
	if (c == '\0')
		data->flag_c0 = 1;
	write(1, data->buffer, ft_strlen(data->buffer));
	ft_bzero(data->buffer, ft_strlen(data->buffer));
	if (data->b_minus == 1)
	{
		write(1, &c, 1);
		ft_display_space(data, space);
	}
	else
	{
		ft_display_space(data, space);
		write(1, &c, 1);
	}
	++data->return_val;
	return (1);
}
