/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:14:13 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/18 17:08:13 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*sr;
	char		*de;
	size_t		len;

	de = dest;
	sr = src;
	while (size != 0 && *de)
	{
		--size;
		++de;
	}
	len = de - dest;
	if (size == 0)
		return (len + ft_strlen(sr));
	while (*sr)
	{
		if (size != 1)
		{
			*de++ = *sr;
			--size;
		}
		sr++;
	}
	*de = '\0';
	return (len + (sr - src));
}
