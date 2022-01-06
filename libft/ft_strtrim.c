/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:52:28 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:54:44 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_check(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_check((s1[--len]), set))
		;
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
