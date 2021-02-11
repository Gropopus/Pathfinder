/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:59:26 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 13:55:01 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*buf_dest;
	unsigned char	*buf_src;

	buf_dest = (unsigned char*)dest;
	buf_src = (unsigned char*)src;
	if (dest == src)
		return (dest);
	while (size--)
	{
		*(buf_dest++) = *(buf_src++);
	}
	return (dest);
}
