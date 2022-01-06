/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:11:20 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 13:52:44 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t max)
{
	size_t			i;
	unsigned char	*buf_dest;
	unsigned char	*buf_src;

	i = 0;
	buf_dest = (unsigned char *)dest;
	buf_src = (unsigned char *)src;
	while (i < max)
	{
		buf_dest[i] = buf_src[i];
		if (buf_dest[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
