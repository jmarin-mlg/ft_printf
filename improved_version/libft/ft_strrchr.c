/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:08:48 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:42:35 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function locates the first occurrence of c (converted to a char) in the
** string pointed to by s. The terminating null character is considered to be
** part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
**
** The ft_strrchr() function is identical to ft_strchr(), except it locates the
** last occurrence of c.
**
** The functions ft_strchr() and ft_strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	searched;
	size_t	i;

	searched = (unsigned char) c;
	i = ft_strlen(s);
	while (i > 0)
		if (s[i--] == searched)
			return ((char *) s + i + 1);
	if (s[i] == searched)
		return ((char *) s + i);
	return (NULL);
}
