/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:47:15 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/25 14:25:47 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_xuint_len(t_data *data, unsigned long int nbr)
{
	unsigned long int	nb;
	int					len;
	unsigned long int	base;

	nb = nbr;
	len = 0;
	if (data->flag == 'u')
		base = 10;
	else if (data->flag == 'x' || data->flag == 'X')
		base = 16;
	else
		return (-1);
	if (nb == 0 && data->b_prec_no_value == 0
		&& (!(data->b_precision && data->precision == 0)))
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

void	ft_xuint_width(t_data *data, int len)
{
	int	end;

	end = 0;
	if (data->b_precision)
		if (data->precision >= len)
			len = data->precision;
	if (data->width > len)
		end = data->width - len;
	if (data->b_zero && data->b_minus)
		data->b_zero = 0;
	while (end > 0)
	{
		if (data->b_zero && data->b_precision == 0
			&& data->b_prec_no_value == 0)
			ft_buffcpy(data, "0");
		else
			ft_buffcpy(data, " ");
		end--;
	}
}

void	ft_xuint_precision(t_data *data, int len)
{
	int	end;

	end = 0;
	if (data->precision > len)
		end = data->precision - len;
	while (end)
	{
		ft_buffcpy(data, "0");
		--end;
	}
}

void	ft_xuint_base_to_buff(t_data *data, unsigned long int nbr, int len)
{
	unsigned long int	base;
	char				str[30];
	char				base_x[17];

	ft_bzero(str, 30);
	ft_bzero(base_x, 17);
	if (data->flag == 'u')
		base = 10;
	else
		base = 16;
	if (data->flag == 'u')
		ft_strcpy(base_x, "0123456789");
	else if (data->flag == 'x')
		ft_strcpy(base_x, "0123456789abcdef");
	else
		ft_strcpy(base_x, "0123456789ABCDEF");
	str[len] = '\0';
	while (len)
	{
		--len;
		str[len] = base_x[nbr % base];
		nbr = nbr / base;
	}
	ft_buffcpy(data, str);
}

int	ft_treat_xuint(t_data *data, int len, unsigned long int nbr)
{
	nbr = (unsigned long int)va_arg(data->args, unsigned int);
	len = ft_get_xuint_len(data, nbr);
	if (len < 0)
		return (-1);
	if (data->b_minus)
	{
		if (data->b_precision)
			ft_xuint_precision(data, len);
		if (!(nbr == 0 && (data->b_prec_no_value
					|| (data->b_precision && data->precision == 0))))
			ft_xuint_base_to_buff(data, nbr, len);
		if (data->b_width)
			ft_xuint_width(data, len);
		return (1);
	}
	if (data->b_width)
		ft_xuint_width(data, len);
	if (data->b_precision)
		ft_xuint_precision(data, len);
	if (!(nbr == 0 && (data->b_prec_no_value
				|| (data->b_precision && data->precision == 0))))
		ft_xuint_base_to_buff(data, nbr, len);
	return (1);
}
