/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:55:25 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:59:41 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_bool(t_data *data)
{
	data->sign_minus = 0;
	data->b_minus = 0;
	data->b_zero = 0;
	data->b_space = 0;
	data->b_plus = 0;
	data->b_diese = 0;
	data->b_width = 0;
	data->b_precision = 0;
	data->width = 0;
	data->precision = 0;
	data->b_prec_no_value = 0;
	data->flag_c0 = 0;
}

static int	ft_check_attribut(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] <= '0' || str[i] > '9')
		&& str[i] != '*' && str[i] != '.')
	{
		if (str[i] == '#')
			data->b_diese = 1;
		if (str[i] == '0')
			data->b_zero = 1;
		if (str[i] == '-')
			data->b_minus = 1;
		if (str[i] == '+')
			data->b_plus = 1;
		if (str[i] == ' ')
			data->b_space = 1;
		if (ft_find_char("#0-+ ", str[i]) < 0)
			return (-1);
		++i;
	}
	return (1);
}

static int	ft_is_width(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] <= '0' || str[i] > '9')
		&& str[i] != '*' && str[i] != '.')
		++i;
	if (str[i] == '*' || (str[i] > '0' && str[i] <= '9'))
		data->b_width = 1;
	while (str && str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
			++i;
		else if (str[i] == '*')
			++i;
		else
			return (-1);
	}
	return (1);
}

static int	ft_is_precision(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == '.')
	{
		++i;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
			data->b_precision = 1;
		else
			data->b_prec_no_value = 1;
	}
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			++i;
		else if (str[i] == '*')
			++i;
		else
			return (-1);
	}
	return (1);
}

int	ft_set_flags(t_data *data, char *str)
{
	if (ft_check_attribut(data, str) <= 0)
		return (-1);
	if (ft_is_width(data, str) <= 0)
		return (-1);
	if (ft_is_precision(data, str) <= 0)
		return (-1);
	return (1);
}
