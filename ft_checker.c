/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 02:23:15 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/11 05:06:31 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ch_field(const char **fmt, va_list *ap, t_ftype *ftype)
{
	int	n;

	n = 0;
	if (**fmt == '*')
	{
		n = va_arg(*ap, int);
		if (n < 0)
		{
			n *= -1;
			ftype->flag[1] = 1;
		}
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
	{
		while(ft_isdigit(**fmt))
			n = n * 10 + ((*(*fmt)++) - '0');
	}
	return (n);
}

int		ch_accu(const char **fmt, va_list *ap)
{
	int	n;

	n = -1;
	if (**fmt == '*')
	{
		n = va_arg(*ap, int);
		if (n < 0)
			n = -1;
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
	{
		n = 0;
		while(ft_isdigit(**fmt))
			n = n * 10 + ((*(*fmt)++) - '0');
	}
	else if (!ft_isdigit(**fmt))
		n = 0;
	return (n);
}