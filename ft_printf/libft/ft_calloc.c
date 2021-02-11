/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:21:34 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 13:41:58 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((str = malloc(count * size)) == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
