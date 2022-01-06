/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:38:12 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:34:41 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)s;
	while (i < size)
	{
		if (buf[i] == (unsigned char)c)
			return (buf + i);
		i++;
	}
	return (NULL);
}
