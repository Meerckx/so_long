/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:32:19 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static long long	ft_reverse(long long n)
{
	long long	nrev;

	nrev = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		nrev = nrev * 10 + (n % 10);
		n /= 10;
	}
	return (nrev);
}

static size_t	ft_lencount(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_numtostr(int n, long long nrev, size_t len)
{
	char	*number;
	size_t	i;

	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	i = 0;
	if (n == 0)
		number[i++] = '0';
	while (n)
	{
		number[i] = (nrev % 10) + '0';
		nrev /= 10;
		n /= 10;
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	*ft_printf_itoa(int n)
{
	long long	nrev;
	size_t		len;
	char		*number;

	len = ft_lencount(n);
	nrev = n;
	nrev = ft_reverse(nrev);
	number = ft_numtostr(n, nrev, len);
	if (!number)
		return (NULL);
	return (number);
}
