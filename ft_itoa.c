/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:08:20 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/07 12:03:21 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_dizaine(int nb)
{
	int	d;

	d = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		d++;
	}
	return (d);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_specific(int n, char *res)
{
	if (n == 0)
		res = ft_strdup("0\0");
	if (n == -2147483648)
		res = ft_strdup("-2147483648\0");
	if (n == 2147483647)
		res = ft_strdup("2147483647\0");
	return (res);
}

char	*ft_second(int *nb, int *size)
{
	char	*r;

	if (*nb < 0)
	{
		*size = ft_dizaine(-(*nb)) + 1;
		r = (char *)malloc((*size + 1) * sizeof(char));
		if (!r)
			return (NULL);
		*nb = -(*nb);
		r[0] = '-';
	}
	else
	{
		*size = ft_dizaine(*nb);
		r = (char *)malloc((*size + 1) * sizeof(char));
		if (!r)
			return (NULL);
	}
	return (r);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*res;

	res = NULL;
	if (n == 0 || n == -2147483648 || n == 2147483647)
	{
		res = ft_specific(n, res);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_second(&n, &size);
	if (!res)
		return (NULL);
	res[size] = '\0';
	i = 0;
	while (i < size && n > 0)
	{
		res[size - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (res);
}
