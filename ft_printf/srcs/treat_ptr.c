/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:19:57 by thsembel          #+#    #+#             */
/*   Updated: 2020/12/02 12:35:34 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ptr_width(t_data *data, unsigned long long int nbr, int len,
int end)
{
	if (nbr == 0 && data->b_prec_no_value == 0)
		len = 3;
	if (data->b_precision)
		if (data->precision >= len)
			len = data->precision;
	if (nbr == 0 && (data->b_prec_no_value
	|| (data->b_precision && data->precision == 0)))
		len = 2;
	if (data->width > len)
		end = data->width - len;
	if (nbr == 0 && (data->b_prec_no_value
	|| (data->b_precision && data->precision == 0)))
		len = 2;
	if (data->b_zero && data->b_minus)
		data->b_zero = 0;
	while (end > 0)
	{
		if (data->b_zero && data->b_precision == 0)
			ft_buffcpy(data, "0");
		else
			ft_buffcpy(data, " ");
		end--;
	}
}

void		ft_ptr_precision(t_data *data, int len)
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

void		ft_ptr_to_buff(t_data *data, unsigned long long int nbr)
{
	int		len;
	char	str[13];
	char	base[17];

	if (nbr == 0 && data->b_width == 0
	&& (data->b_precision || data->b_prec_no_value))
		return ;
	ft_bzero(str, 13);
	ft_bzero(base, 17);
	ft_strcpy(base, "0123456789abcdef");
	len = ft_get_hexlen(nbr) - 2;
	if (nbr == 0)
		len = 1;
	str[len] = '\0';
	while (len)
	{
		--len;
		str[len] = base[nbr % 16];
		nbr = nbr / 16;
	}
	ft_buffcpy(data, str);
}

void		ft_ptr_minus(t_data *data, unsigned long long nbr, int len)
{
	ft_buffcpy(data, "0x");
	if (data->b_precision && data->precision != 0)
		data->precision += 2;
	if ((data->b_precision && data->precision != 0)
	&& (data->b_precision == 0 || data->precision != 0))
		ft_ptr_precision(data, len);
	if (data->b_prec_no_value == 0 || nbr != 0)
		ft_ptr_to_buff(data, nbr);
	if (data->b_width)
		ft_ptr_width(data, nbr, len, 0);
}

int			ft_treat_ptr(t_data *data, unsigned long long int nbr, int len)
{
	nbr = (unsigned long long int)va_arg(data->args, void *);
	len = ft_get_hexlen(nbr);
	if (data->b_minus)
	{
		ft_ptr_minus(data, nbr, len);
		return (1);
	}
	if (data->b_precision && data->precision != 0)
		data->precision += 2;
	if (data->b_width)
		ft_ptr_width(data, nbr, len, 0);
	ft_buffcpy(data, "0x");
	if (data->b_precision && data->precision != 0)
		ft_ptr_precision(data, len);
	if (data->b_prec_no_value == 0 || nbr != 0)
		ft_ptr_to_buff(data, nbr);
	return (1);
}
