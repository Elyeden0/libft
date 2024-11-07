/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnard <abonnard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:00:27 by abonnard          #+#    #+#             */
/*   Updated: 2024/11/07 14:22:46 by abonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
    int	count;
    int	in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char	*allocate_word(const char *s, char c)
{
    int		len;
    char	*word;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    for (int i = 0; i < len; i++)
        word[i] = s[i];
    word[len] = '\0';
    return (word);
}

static void	free_tab(char **tab, int j)
{
    while (j >= 0)
        free(tab[j--]);
    free(tab);
}

char	**ft_split(char const *s, char c)
{
    char	**tab;
    int		words;
    int		i;
    int		j;

    if (!s)
        return (NULL);
    words = count_words(s, c);
    tab = malloc(sizeof(char *) * (words + 1));
    if (!tab)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            tab[j] = allocate_word(&s[i], c);
            if (!tab[j])
            {
                free_tab(tab, j - 1);
                return (NULL);
            }
            j++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    tab[j] = NULL;
    return (tab);
}
