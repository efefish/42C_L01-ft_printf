/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:04:28 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/02/17 07:26:00 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_ftype {
	int flag[2];
	int field;
	int accu;
	int spec;
	int output_len;
}				t_ftype;

int		ft_printf(const char *fmt, ...);
int		ft_strai_write(const char **fmt, const char **array);
int		ft_ch_perc(const char **fmt, va_list *ap);
void	ft_flag_init(t_ftype *ftype);
int		ft_ch_spec(const char **fmt,
		va_list *ap, t_ftype *ftype);

int		ch_field(const char **fmt, va_list *ap, t_ftype *ftype);
int		ch_accu(const char **fmt, va_list *ap);

void	ft_print_char(va_list *ap, t_ftype *ftype);
void	ft_print_str(va_list *ap, t_ftype *ftype);
int		ft_check_str(va_list *ap, t_ftype *ftype, char **s);
int		ft_print_null(t_ftype *ftype, char **s);
void	ft_print_poi(va_list *ap, t_ftype *ftype);

void	ft_print_percent(t_ftype *ftype);
void	ft_print_int(va_list *ap, t_ftype *ftype);
void	ft_check_int(t_ftype *ftype, long long n);
int		ch_int_digit(long long n);

void	ft_print_unsigned(va_list *ap, t_ftype *ftype);
void	ft_check_unsigned(t_ftype *ftype, unsigned long long n);
int		ch_unsigned_digit(unsigned long long n, t_ftype *ftype);
void	ft_write_change(unsigned long long n, char *base, unsigned int size);
void	ft_write_intux(unsigned long long n, t_ftype ftype);

int		ft_printf_strchr2(const char *s, char c);
int		ft_printf_strchr9(const char *s, char c);
int		ft_isdigit(int c);
void	ft_write_space(char c, int n);
size_t	ft_strlen(const char *s);


#endif