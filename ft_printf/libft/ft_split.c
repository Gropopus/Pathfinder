/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:09:35 by thsembel          #+#    #+#             */
/*   Updated: 2020/11/17 13:24:45 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_charsep(char str, char c)
{
	if (c == str)
		return (1);
	else if (str == '\0')
		return (1);
	return (0);
}

static int		ft_count_words(const char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if ((ft_find_charsep(str[i + 1], c) == 1 &&
				ft_find_charsep(str[i], c) == 0))
			word++;
		i++;
	}
	return (word);
}

static void		ft_copy_word(char *dest, const char *from, char c)
{
	int i;

	i = 0;
	while (ft_find_charsep(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void		ft_transfert(char **tab, const char *str, char c)
{
	int i;
	int word;
	int j;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_find_charsep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_find_charsep(str[i + j], c) == 0)
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			ft_copy_word(tab[word], str + i, c);
			i = i + j;
			word++;
		}
	}
}

char			**ft_split(char const *str, char c)
{
	char	**tab;
	int		word;

	if (!str)
		return (NULL);
	word = ft_count_words(str, c);
	if ((tab = (char**)malloc(sizeof(char*) * (word + 1))) == NULL)
		return (NULL);
	tab[word] = 0;
	ft_transfert(tab, str, c);
	return (tab);
}
