/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:05:37 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/17 13:22:57 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(int nb)
{
	long	tmp;
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb == -2147483648)
		return (11);
	tmp = nb;
	if (nb < 0)
	{
		tmp = -nb;
		len++;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	neg;

	neg = 0;
	len = ft_get_len(n);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		neg = 1;
		str[0] = '-';
	}
	while (len > neg)
	{
		len--;
		if (n < 0)
			str[len] = (n % 10) * (-1) + '0';
		else
			str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
