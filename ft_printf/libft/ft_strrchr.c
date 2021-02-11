/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:43:14 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 14:54:29 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == c)
			return ((char*)str + len);
		len--;
	}
	return (NULL);
}
