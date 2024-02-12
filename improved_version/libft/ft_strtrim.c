/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:43:31 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/29 10:40:08 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** s1: The string that should be trimmed.
** set: The characters to remove from the string.
**
** Returns the trimmed string or NULL if memory allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	len = ft_strlen(s1);
	while (len >= 1 && ft_strchr(set, s1[len]))
		--len;
	return (ft_substr(s1, 0, len + 1));
}
