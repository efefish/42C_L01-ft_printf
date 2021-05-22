/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_per_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:03:01 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/17 08:01:25 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_ftype *ftype)
{
	ftype->output_len = 1;
	if (ftype->field <= ftype->output_len)
		ftype->field = 0;
	else
		ftype->field -= ftype->output_len;
	if (ftype->flag[1] == 0 && ftype->flag[0] == 0)
		ft_write_space(' ', ftype->field);
	if (ftype->flag[0] == 1 && ftype->flag[1] == 0)
		ft_write_space('0', ftype->field);
	write(1, "%%", 1);
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}

void	ft_print_int(va_list *ap, t_ftype *ftype)
{
	long long 	n;

	n = va_arg(*ap, int);
	ft_check_int(ftype, n);
	if (ftype->flag[0] == 0 && ftype->flag[1] == 0)
		ft_write_space(' ', ftype->field);
	if (n < 0)
		write(1, "-", 1);
	if (ftype->flag[0] == 1 && ftype->flag[1] == 0)
		ft_write_space('0', ftype->accu + ftype->field);
	else
		ft_write_space('0', ftype->accu);
	if (n < 0)
		n *= -1;
	if (n)
		ft_write_intux(n, *ftype);
	if (ftype->flag[1] == 1)
		ft_write_space(' ', ftype->field);
}

void	ft_check_int(t_ftype *ftype, long long n)
{
	if (!(ftype->accu == -1))
		ftype->flag[0] = 0;
	ftype->output_len = ch_int_digit(n);
	if (ftype->accu <= ftype->output_len)
		ftype->accu = (n == 0 && ftype->accu);
	else
		ftype->accu -= ftype->output_len;
	if (n < 0)
		ftype->output_len += ftype->accu + 1;
	else
		ftype->output_len += ftype->accu;
	if (ftype->field <= ftype->output_len)
		ftype->field = 0;
	else
		ftype->field -= ftype->output_len;
}

int		ch_int_digit(long long n)
{
	int					i;
	unsigned long long	nyan;

	i = 0;
	if (n < 0)
		nyan = -n;
	else
		nyan = n;
	while (nyan > 0)
	{
		nyan /= 10;
		i++;
	}
	return (i);
}