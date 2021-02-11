/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:51:44 by thsembel          #+#    #+#             */
/*   Updated: 2021/01/09 13:17:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_hexlen(unsigned long long int nbr)
{
	int								len;
	unsigned	long	long	int	nb;

	len = 0;
	nb = nbr;
	while (nb)
	{
		nb /= 16;
		++len;
	}
	len = len + 2;
	return (len);
}
