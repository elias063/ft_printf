/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/17 17:10:33 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *str, size_t len)
{
	unsigned int	i;
	char			*copy;

	if (!(copy = malloc(sizeof(*copy) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_strlen(char *base)
{
	int i = 0;

	while (base[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	long i;
	long nb;
	int j;

	i = 0;
	nb = 0;
	if (*str == '-')
	{
		i++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if (nb > LONG_MAX || nb < 0)
			return (i > 0) ? 0 : -1;
	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}

int	countdigit_d_i_u(int nb)
{
	int digit = 1;
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb <= 9)
		return(++digit); 		
	while (nb > 9)
	{
		nb /= 10;
		digit++;
	}	
	return(digit);
}

static int    countdigit(int n)
{
    int                len;
    unsigned int    nb;

    len = 0;
    nb = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        len++;
        nb = (unsigned int)(n * -1);
    }
    else
        nb = (unsigned int)n;
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

void       ft_itoa_custom(int n, char *arr)
{
    unsigned int    nb;
    int                sign;
    int                len;
 
    sign = 0;
    len = countdigit(n);
    if (n < 0)
    {
        sign = 1;
        nb = (unsigned int)(n * -1);
        *arr = '-';
    }
    else
        nb = (unsigned int)n;
    while (len-- > sign)
    {
        arr[len] = nb % 10 + '0';
        nb = nb / 10;
    }
}

void        ft_itoa_custom_pos(int n, char *arr)
{
    unsigned int    nb;
    int                sign;
    int                len;
 
    sign = 0;
    len = countdigit(n);
    if (n < 0)
    {
        sign = 1;
        nb = (unsigned int)(n * -1);
    }
    else
        nb = (unsigned int)n;
    while (len-- > sign)
    {
        arr[len] = nb % 10 + '0';
        nb = nb / 10;
    }
}

/*void       ft_itoa_custom_hexa(int n, char *arr, char *base)
{
    unsigned int    nb;
    int                sign;
    int                len;
 
    sign = 0;
    len = countdigit(n);
    if (n < 0)
    {
        sign = 1;
        nb = (unsigned int)(n * -1);
       // *arr = '-';
    }
    else
        nb = (unsigned int)n;
    while (len-- > sign)
    {
        arr[len] = &base[nb % 16];
        nb = nb / 10;
    }
}*/

void		ft_putnbr_base(int n, char *base, char *str)
{
	unsigned int nb;
	int a;
	static int i = 0;
	int y;

	y = 0;
	if (i != 0)
		i = y;
	a = ft_strlen(base);
	nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_base((nb / a), base, str);
	str[i++] = base[nb % a];
}

void	ft_putnbr_base_p(int nbr, char *base)
{
	unsigned int nb;
	int a;

	a = ft_strlen(base);
	nb = (unsigned int)nbr;
	if (nb > 9)
		ft_putnbr_base_p((nb / a), base);
	write(1, &base[ nb % a], 1);
}