/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_chr_str_poi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:16:09 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/26 12:59:28 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list *ap, t_ftype *ftype)
{
	char	c;

	c = (char)va_arg(*ap, int);
	ftype->output_len = 1;
	if (ftype->field <= ftype->output_len)
		ftype->field = 0;
	else
		ftype->field -= ftype->output_len;
	if (ftype->flag[1] == 0)
		ft_write_space(' ', ftype->field);
	write(1, &c, 1);
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}

void	ft_print_str(va_list *ap, t_ftype *ftype)
{
	char	*s;

	ft_check_str(ap, ftype, &s);
	if (ftype->field <= ftype->output_len)
		ftype->field = 0;
	else if (ftype->field > ftype->output_len)
		ftype->field -= ftype->output_len;
	if (ftype->flag[1] == 0)
	{
		if (ftype->flag[0] == 0)
			ft_write_space(' ', ftype->field);
		else if (ftype->flag[0] == 1)
			ft_write_space('0', ftype->field);
	}
	write(1, s, ftype->output_len);		
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}

int		ft_check_str(va_list *ap, t_ftype *ftype, char **s)
{
	int		n;

	if (ap == NULL)
		return (ft_print_null(ftype, s));
	*s = (char *)va_arg(*ap, char *);
	if (*s == NULL)
		return (ft_print_null(ftype, s));
	n = (int)ft_strlen(*s);
	if (ftype->accu >= n || ftype->accu <= -1)
		ftype->output_len = n;
	else if (ftype->accu < n)
		ftype->output_len = ftype->accu;
	return (n);
}

int		ft_print_null(t_ftype *ftype, char **s)
{
	*s = "(null)";
	ftype->output_len = 6;
	if (6 > ftype->accu && ftype->accu != -1)
		ftype->output_len = ftype->accu;
	return (0);
}

void	ft_print_poi(va_list *ap, t_ftype *ftype)
{
	unsigned long long	n;
	
	n = (unsigned long long)va_arg(*ap, void *);
	ft_check_unsigned(ftype, n);
	if (n == 0 && ftype->field == 0)
		ftype->output_len += 2; 
	else if (n == 0)
	{
		ftype->output_len += 2;
		ftype->field -= 2;
	}
	if (ftype -> field < 0)
		ftype->field = 0;
	if (ftype->flag[0] == 0 && ftype->flag[1] == 0)
		ft_write_space(' ', ftype->field);
	write(1, "0x", 2);
	if (ftype->flag[0] == 1 && ftype->flag[1] == 0)
		ft_write_space('0', ftype->accu + ftype->field);
	else
		ft_write_space('0', ftype->accu);
	if (n)
		ft_write_intux(n, *ftype);
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}
