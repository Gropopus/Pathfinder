/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:34 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/24 13:40:39 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	va_list		args;
	size_t		i;
	char		buffer[1024];
	char		copy[100];
	char		flag;
	int			sign_minus;
	int			b_zero;
	int			b_space;
	int			b_minus;
	int			b_plus;
	int			b_diese;
	int			b_width;
	int			b_precision;
	int			width;
	int			precision;
	int			b_prec_no_value;
	int			flag_c0;
	int			return_val;
}				t_data;

void			ft_init_buf(t_data *data, size_t *j);
void			ft_reset_bool(t_data *data);
void			ft_buffcpy(t_data *data, char *str);
void			ft_strcat_char(t_data *data, const char c);
void			ft_treat_modulo(t_data *data);
int				ft_get_hexlen(unsigned long long int nbr);
int				ft_get_precision(t_data *data, char *str, int i);
int				ft_get_width(t_data *data, char *str, int i);
int				ft_set_flags(t_data *data, char *str);
int				ft_treat_int(t_data *data);
int				ft_treat_string(t_data *data);
int				ft_treat_char(t_data *data);
int				ft_treat_ptr(t_data *data, unsigned long long int nbr, int len);
int				ft_treat_xuint(t_data *data, int len, unsigned long int nbr);
int				ft_printf(const char *str, ...);
int				ft_get_tens(long int nbr);
int				ft_find_char(char *str, char c);
int				ft_check_convert(t_data *data, char *str);
int				ft_get_convert(t_data *data, va_list *args, char *str);

#endif
