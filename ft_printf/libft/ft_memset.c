/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:07:33 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 13:56:31 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t count)
{
	unsigned char	*buf;

	buf = (unsigned char *)str;
	while (count--)
		*buf++ = c;
	return (str);
}
