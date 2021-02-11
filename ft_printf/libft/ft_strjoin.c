/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:31:45 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/16 14:41:08 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	int				i;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((res = malloc(sizeof(char) * (len_s1 + len_s2 + 1))) == NULL)
		return (NULL);
	res[len_s1 + len_s2] = '\0';
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	return (res);
}
