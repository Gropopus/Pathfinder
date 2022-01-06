/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:19:11 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:53:48 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	else
	{
		while (big[i])
		{
			j = 0;
			while ((little[j] == big[i + j]) && i + j < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
