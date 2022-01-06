/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:58:15 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:41:28 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_buf(t_data *data, size_t *j)
{
	write(1, data->buffer, ft_strlen(data->buffer));
	ft_bzero(data->buffer, 1024);
	*j = 0;
	return ;
}

void	ft_buffcpy(t_data *data, char *str)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(data->buffer);
	while (str[i])
	{
		if (j >= 1023)
			ft_init_buf(data, &j);
		++data->return_val;
		data->buffer[j] = str[i];
		++j;
		++i;
	}
	data->buffer[j] = '\0';
	return ;
}

int	ft_get_tens(long int nbr)
{
	int			len;
	long int	tmp;

	len = 0;
	tmp = nbr;
	if (tmp <= 0)
		++len;
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	return (len);
}

int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strcat_char(t_data *data, const char c)
{
	int	i;

	i = 0;
	if (ft_find_char("c", data->flag) >= 0 && c == '\0')
	{
		write(1, data->buffer, ft_strlen(data->buffer));
		ft_bzero(data->buffer, ft_strlen(data->buffer));
		write(1, &c, 1);
		data->return_val++;
		return ;
	}
	while (data->buffer[i])
		++i;
	data->buffer[i] = c;
	++i;
	data->buffer[i] = '\0';
	++data->return_val;
}
