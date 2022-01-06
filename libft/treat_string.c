/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:21:33 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 14:34:32 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_width(t_data *data, char *str)
{
	int		i;
	int		end;
	size_t	j;

	if (data->b_prec_no_value)
		return ;
	i = 0;
	j = ft_strlen(data->buffer);
	if (data->b_precision && data->precision < (int)ft_strlen(str))
		end = data->precision;
	else
		end = (int)ft_strlen(str);
	while (str && i < end)
	{
		if (j >= 1023)
			ft_init_buf(data, &j);
		data->buffer[j] = str[i];
		++data->return_val;
		++j;
		++i;
	}
	data->buffer[j] = '\0';
}

int	ft_minus(t_data *data, char *str)
{
	int		len;
	int		end;

	end = 0;
	len = 0;
	if (data->b_width)
		end = data->width;
	if ((data->precision > (int)ft_strlen(str) || data->b_precision == 0)
		&& data->b_prec_no_value == 0)
		len = (int)ft_strlen(str);
	else if (data->b_prec_no_value == 0)
		len = data->precision;
	ft_precision_width(data, str);
	while (str && len < end)
	{
		ft_buffcpy(data, " ");
		++len;
	}
	return (1);
}

static int	ft_do_convert_string(t_data *data, char *str)
{
	int		len;
	int		end;

	end = 0;
	len = 0;
	if (data->b_minus)
		return (ft_minus(data, str));
	if (data->b_precision && data->precision < (int)ft_strlen(str))
		len = data->precision;
	else if (data->b_prec_no_value == 0)
		len = (int)ft_strlen(str);
	if (data->b_width && data->width > len)
		end = data->width;
	while (str && len < end)
	{
		if (data->b_zero)
			ft_buffcpy(data, "0");
		else
			ft_buffcpy(data, " ");
		++len;
	}
	ft_precision_width(data, str);
	return (1);
}

int	ft_treat_string(t_data *data)
{
	char	*str;

	str = NULL;
	str = va_arg(data->args, char *);
	if (str == NULL)
		return (ft_do_convert_string(data, "(null)"));
	if (ft_do_convert_string(data, str) <= 0)
		return (-1);
	return (1);
}
