/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:50:57 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:38:33 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch_format(t_data *data, char c)
{
	int	ret;

	ret = 0;
	data->flag = c;
	if (c == 'd' || c == 'i')
		ret = ft_treat_int(data);
	else if (c == 'u')
		ret = ft_treat_xuint(data, 0, 0);
	else if (c == 'x' || c == 'X')
		ret = ft_treat_xuint(data, 0, 0);
	else if (c == 'p')
		ret = ft_treat_ptr(data, 0, 0);
	else if (c == 'c')
		ret = ft_treat_char(data);
	else if (c == 's')
		ret = ft_treat_string(data);
	else if (c == '%')
		ft_treat_modulo(data);
	else if (ft_find_char("cspdiuxX%", c) < 0 || ret <= 0)
		return (-1);
	return (1);
}

static int	ft_init_flags(t_data *data, char *str)
{
	ft_reset_bool(data);
	if (ft_set_flags(data, str) < 0)
		return (-1);
	if (ft_get_width(data, str, 0) < 0)
		return (-1);
	if (ft_get_precision(data, str, 0) < 0)
		return (-1);
	return (1);
}

static int	ft_set_data(t_data *data, const char *str, size_t *i)
{
	size_t	j;

	j = 0;
	ft_bzero(data->copy, 100);
	while (ft_find_char("cspdiuxX%", str[*i]) < 0 && str[*i])
	{
		if (j == 99)
		{
			data->copy[j] = '\0';
			if (ft_init_flags(data, data->copy) < 0)
				return (-1);
			ft_bzero(data->copy, 100);
			j = 0;
		}
		data->copy[j] = str[*i];
		j++;
		++*i;
	}
	data->copy[j] = '\0';
	if (ft_init_flags(data, data->copy) < 0
		|| ft_switch_format(data, str[*i]) < 0)
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.args, str);
	data.i = 0;
	data.return_val = 0;
	ft_bzero(data.buffer, 1024);
	while (str && str[data.i])
	{
		if (data.i != 0 && str[data.i - 1] == '%')
		{
			if (ft_set_data(&data, str, &data.i) < 0)
			{
				va_end(data.args);
				return (-1);
			}
			data.i++;
		}
		if (str[data.i] && str[data.i] != '%')
			ft_strcat_char(&data, str[data.i]);
		if (str[data.i])
			data.i++;
	}
	write(1, data.buffer, ft_strlen(data.buffer));
	va_end(data.args);
	return (data.return_val);
}
