/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:58:57 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:35:11 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t				i;
	const unsigned char	*buf_s1;
	const unsigned char	*buf_s2;

	i = 0;
	buf_s1 = (const unsigned char *)s1;
	buf_s2 = (const unsigned char *)s2;
	while (i < size)
	{
		if (buf_s1[i] != buf_s2[i])
			return (buf_s1[i] - buf_s2[i]);
		i++;
	}
	return (0);
}
