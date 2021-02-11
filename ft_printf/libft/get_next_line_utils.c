/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:18:30 by thsembel          #+#    #+#             */
/*   Updated: 2021/01/09 13:08:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_null(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_check_c(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

int		ft_free_and_exit(char **str, char **new_line)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (new_line && *new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	return (-1);
}
