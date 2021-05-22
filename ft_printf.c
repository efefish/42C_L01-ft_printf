/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:04:45 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/17 07:13:48 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ch_spec(const char **fmt, va_list *ap, t_ftype *ftype)
{
	if (ftype->spec == -1)
		return (-1);
	(*fmt)++;
	if(ftype->spec == 0)
		ft_print_char(ap, ftype);
	else if(ftype->spec == 1)
		ft_print_str(ap, ftype);
	else if(ftype->spec == 2)
		ft_print_poi(ap, ftype);
	else if(ftype->spec == 3 || ftype->spec == 4)
		ft_print_int(ap, ftype);
	else if(ftype->spec >= 5 && ftype->spec <= 7)
		ft_print_unsigned(ap, ftype);
	else if(ftype->spec == 8)
		ft_print_percent(ftype);
	return(ftype->output_len + ftype->field);
}

void	ft_flag_init(t_ftype *ftype)
{
	ftype->flag[0] = 0;
	ftype->flag[1] = 0;
	ftype->field = 0;
	ftype->accu = -1;
	ftype->spec = -1;
	ftype->output_len = 0;
}

int		ft_ch_perc(const char **fmt, va_list *ap)
{
	int		n;
	t_ftype	ftype;

	(*fmt)++;
	ft_flag_init(&ftype);
	while ((n = ft_printf_strchr2("0-", **fmt)) >= 0)
	{
		ftype.flag[n] = 1;
		(*fmt)++;
	}
	ftype.field = ch_field(fmt, ap, &ftype);
	if (**fmt == '.')
	{
		(*fmt)++;
		ftype.accu = ch_accu(fmt, ap);
	}
	ftype.spec = ft_printf_strchr9("cspdiuxX%", **fmt);
	return (ft_ch_spec(fmt, ap, &ftype));
}

int		ft_strai_write(const char **fmt, const char **array)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *array, *fmt - *array);
	return (*fmt - *array);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	const char	*array;
	int			n;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while(*fmt)
	{
		array = fmt;
		if(*array != '%')
			n += ft_strai_write(&fmt, &array);
		else
			n += ft_ch_perc(&fmt, &ap);
	}
	va_end(ap);
	return(n);
}