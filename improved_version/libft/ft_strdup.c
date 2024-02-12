/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 07:15:02 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:36:50 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function allocates sufficient memory for a copy of the string s1, does
** the copy, and returns a pointer to it.  The pointer may subsequently be used
** as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
*/
char	*ft_strdup(const char *s1)
{
	size_t	size;
	void	*res;

	size = ft_strlen(s1) + 1;
	res = malloc(size);
	if (res == NULL)
		return (res);
	ft_strlcpy(res, s1, size);
	return (res);
}
