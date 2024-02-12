/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:34:51 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/04 18:55:05 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** s: The string to separate.
** c: Delimiting character.
**
** Returns the array of new strings resulting from the split or NULL if memory
** allocation fails.
*/
static int	ft_count_words(const char *s, char c)
{
	int	n_words;
	int	found;

	n_words = 0;
	found = 0;
	while (*s)
	{
		if (*s != c && found == 0)
		{
			found = 1;
			++n_words;
		}
		else if (*s == c)
			found = 0;
		++s;
	}
	return (n_words);
}

static char	*ft_save_word(const char *s, int start, int end)
{
	char	*res;
	int		i;

	res = (char *) ft_calloc((end - start + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

static void	ft_free_memory(char **split, int index)
{
	while (index-- > 0)
		free(split[index]);
	free(split);
	return ;
}

char	**ft_split(char const *s, char c)
{
	t_split	t;

	t.len = ft_strlen(s);
	t.i_st = 0;
	t.i_sp = 0;
	t.i_wo = -42;
	t.split = (char **) ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!t.split)
		return (NULL);
	while (t.i_st++ <= t.len)
	{
		if (s[t.i_st - 1] != c && t.i_wo == -42)
			t.i_wo = t.i_st - 1;
		else if ((s[t.i_st - 1] == c || (t.i_st - 1) == t.len) && t.i_wo != -42)
		{
			t.split[t.i_sp++] = ft_save_word(s, t.i_wo, t.i_st - 1);
			if (!t.split[t.i_sp - 1])
			{
				ft_free_memory(t.split, t.i_sp - 1);
				return (NULL);
			}
			t.i_wo = -42;
		}
	}
	return (t.split);
}
