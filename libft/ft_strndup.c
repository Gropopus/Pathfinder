/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:06:44 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/13 15:08:17 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *string, size_t len)
{
	char	*ret;
	size_t	index;

	index = 0;
	if (string == NULL)
	{
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret != NULL)
	{
		while (index < len)
		{
			ret[index] = string[index];
			index++;
		}
		ret[index] = '\0';
	}
	return (ret);
}
