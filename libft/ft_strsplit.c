/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:11:16 by kdaou             #+#    #+#             */
/*   Updated: 2018/10/17 19:19:18 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc(char const *s, char c)
{
	size_t	words;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_len(char const *s, char c, int tl)
{
	size_t	len;

	len = 0;
	while (s[tl] && s[tl] != c)
	{
		tl++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		t;
	size_t	n;

	n = 0;
	t = 0;
	if (!s)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * (ft_calc(s, c) + 1))))
		return (NULL);
	while (n < ft_calc(s, c))
	{
		i = 0;
		while (s[t] == c)
			t++;
		if (!(new[n] = (char *)malloc(sizeof(char) * (ft_len(s, c, t) + 1))))
			return (NULL);
		while (s[t] != c && s[t] != '\0')
			new[n][i++] = s[t++];
		new[n][i] = '\0';
		n++;
	}
	new[n] = NULL;
	return (new);
}
