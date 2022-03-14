/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:20:57 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 18:02:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_flags
{
	char	types[10];
	char	flag[6];
	char	type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		star;
	int		plus;
	int		space;
	int		sharp;
	int		error;
}				t_flags;

typedef struct s_hex
{
	char	uppercase[17];
	char	lowercase[17];
}				t_hex;

int		ft_printf(const char *format, ...);
void	ft_hex_init(t_hex *hex);
void	ft_print_list(t_list *list);
void	ft_print_list_char(t_list *list);
size_t	ft_parsing(const char *format, va_list ap);

size_t	ft_specifier_parsing(const char *format, va_list ap,
			size_t i, t_flags *flags);
size_t	ft_specifier_error(const char *format, size_t i,
			t_flags *flags, size_t *length);

size_t	ft_star_precision(va_list ap, size_t i, t_flags *flags);
size_t	ft_digit_precision(const char *format, size_t i, t_flags *flags);
size_t	ft_star_width(va_list ap, size_t i, t_flags *flags);
size_t	ft_digit_width(const char *format, size_t i, t_flags *flags);

size_t	ft_plus_flag(const char *format, size_t i, t_flags *flags);
size_t	ft_minus_flag(const char *format, size_t i, t_flags *flags);
size_t	ft_zero_flag(const char *format, size_t i, t_flags *flags);
size_t	ft_space_flag(const char *format, size_t i, t_flags *flags);
size_t	ft_sharp_flag(const char *format, size_t i, t_flags *flags);

size_t	ft_processor(va_list ap, t_flags *flags);
size_t	ft_char_type(int ch, t_flags *flags);
size_t	ft_str_type(char *str, t_flags *flags);
size_t	ft_intdec_type(int num, t_flags *flags);
size_t	ft_uint_type(unsigned int num, t_flags *flags);
size_t	ft_pointer_type(unsigned long num, t_flags *flags);
size_t	ft_hex_type(unsigned int num, t_flags *flags);
size_t	ft_percent_type(t_flags *flags);

int		ft_isflag(char ch, t_flags *flags);
int		ft_istypes(char ch, t_flags *flags);

char	*ft_printf_itoa(int n);
char	*ft_itoa_uint(unsigned int n);

#endif