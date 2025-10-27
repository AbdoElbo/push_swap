/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:09:11 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/15 15:43:07 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

static size_t	word_len(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] && !is_space(s[i]))
	{
		len++;
		i++;
	}
	return (len);
}

size_t	word_count(char const *s)
{
	size_t		i;
	size_t		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((!is_space(s[i])) && (i == 0 || is_space(s[i - 1])))
			words++;
		i++;
	}
	return (words);
}

char	**free_arr(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split_push(char const *s)
{
	char	**arr;
	size_t	i;
	size_t	n;
	size_t	sub_len;

	arr = malloc(sizeof(char *) * (word_count(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		if ((!is_space(s[i])) && (i == 0 || is_space(s[i - 1])))
		{
			sub_len = word_len(&s[i]);
			arr[n] = malloc(sub_len + 1);
			if (arr[n] == NULL)
				return (free_arr(arr, n));
			ft_strlcpy(arr[n], &s[i], sub_len + 1);
			n++;
		}
		i++;
	}
	arr[n] = NULL;
	return (arr);
}
