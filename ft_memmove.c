/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:33:24 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/04 17:17:34 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 < str2)
	{
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
	}
	return (dst);
}

/*int main()
{
    char str1[] = "Hello";
    char str2[] = "World";

    printf("Before memmove:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    ft_memmove(str1, str2, 3);

    printf("After memmove:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}*/
