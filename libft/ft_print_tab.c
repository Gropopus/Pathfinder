/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:10:46 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:36:21 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL || tab[0] == NULL)
		return ;
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
