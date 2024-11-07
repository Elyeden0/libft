/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:15:10 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/07 14:22:42 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*allocate_str(size_t len1, size_t len2)
{
	char	*str;

	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	return (str);
}

static void	copy_str(char *dest, const char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
}

static size_t	get_len(const char *s)
{
	if (s == NULL)
		return (0);
	return (ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = get_len(s1);
	len2 = get_len(s2);
	str = allocate_str(len1, len2);
	if (!str)
		return (NULL);
	i = 0;
	if (s1 != NULL)
		copy_str(str, s1, &i);
	if (s2 != NULL)
		copy_str(str, s2, &i);
	str[i] = '\0';
	return (str);
}
