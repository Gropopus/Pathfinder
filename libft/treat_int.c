/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:05:12 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 14:30:41 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_intobuff(t_data *data, long int nbr)
{
	int		len;
	int		np;
	char	str[33];

	if (nbr == 0 && ((data->b_precision && data->precision == 0)
			|| data->b_prec_no_value))
		return ;
	ft_bzero(str, 33);
	len = ft_get_tens(nbr);
	np = 0;
	str[len] = '\0';
	if (nbr < 0)
	{
		np = 1;
		nbr = nbr * (-1);
	}
	while (len)
	{
		--len;
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (np)
		str[0] = '-';
	ft_buffcpy(data, str);
}

int	ft_end(t_data *data, long int nbr, int len)
{
	int	i;

	i = 0;
	if (data->b_precision)
	{
		if (data->precision >= len)
		{
			if (nbr < 0 || (data->b_minus && data->sign_minus))
				len = data->precision + 1;
			else
				len = data->precision;
		}
	}
	if (data->width > len)
		i = data->width - len;
	if (nbr == 0 && (data->b_prec_no_value
			|| (data->b_precision && data->precision == 0)))
		++i;
	return (i);
}

int	ft_int_width(t_data *data, long int nbr, int len)
{
	int	i;
	int	np;

	np = 1;
	i = ft_end(data, nbr, len);
	if (data->b_minus && data->b_zero)
		data->b_zero = 0;
	if (nbr < 0 && data->b_zero && data->b_precision == 0
		&& data->b_prec_no_value == 0)
	{
		ft_buffcpy(data, "-");
		np = (-1);
	}
	while (i > 0)
	{
		if (data->b_zero && data->b_precision == 0
			&& data->b_prec_no_value == 0)
			ft_buffcpy(data, "0");
		else
			ft_buffcpy(data, " ");
		--i;
	}
	return (np);
}

int	ft_int_precision(t_data *data, long int nbr, int len)
{
	int	sign;
	int	end;

	end = 0;
	sign = 1;
	if (nbr < 0)
	{
		--len;
		ft_buffcpy(data, "-");
		sign = (-1);
		data->sign_minus = 1;
	}
	if (data->precision > len)
		end = data->precision - len;
	while (end)
	{
		ft_buffcpy(data, "0");
		--end;
	}
	return (sign);
}

int	ft_treat_int(t_data *data)
{
	long int	nbr;
	int			len;
	int			np;

	np = 1;
	nbr = va_arg(data->args, int);
	len = ft_get_tens(nbr);
	if (data->b_minus)
	{
		if (data->b_precision)
			np = ft_int_precision(data, nbr, len);
		nbr = nbr * np;
		ft_intobuff(data, nbr);
		if (data->b_width && data->width)
			ft_int_width(data, nbr, len);
		return (0);
	}
	if (data->b_width && data->width)
		np = ft_int_width(data, nbr, len);
	if (data->b_precision)
		np = ft_int_precision(data, nbr, len);
	nbr = nbr * np;
	ft_intobuff(data, nbr);
	return (1);
}
