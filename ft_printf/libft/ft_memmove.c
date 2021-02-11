/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:31:18 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 15:02:47 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*buf_dst;
	unsigned char	*buf_src;

	i = 0;
	buf_dst = (unsigned char*)dst;
	buf_src = (unsigned char*)src;
	if (src == dst)
		return (dst);
	if (buf_src < buf_dst)
	{
		while (++i <= size)
			buf_dst[size - i] = buf_src[size - i];
	}
	else
		ft_memcpy(dst, src, size);
	return (dst);
}
