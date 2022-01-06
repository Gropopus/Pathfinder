/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:31:45 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/05 14:28:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	int				i;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (res == NULL)
		return (NULL);
	res[len_s1 + len_s2] = '\0';
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free(&s1);
	res = ft_strcat(res, (char *)s2);
	free(&s2);
	return (res);
}
