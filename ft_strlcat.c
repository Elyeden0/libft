/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:07:19 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/04 17:19:29 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j])
		j++;
	if (i == dstsize)
		return (i + j);
	while (src[k] && i + k < dstsize - 1)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}

/*int main()
{
    char dest[20] = "Hello,";
    const char *src = "World!";
    size_t dstsize = 20;
    size_t result;

    printf("Before strlcat:\n");
    printf("dest: '%s'\n", dest);
    printf("src: '%s'\n", src);

    result = ft_strlcat(dest, src, dstsize);

    printf("After strlcat:\n");
    printf("dest: '%s'\n", dest);
    printf("src: '%s'\n", src);
    printf("Total length: %zu\n", result);

    return 0;
}*/
