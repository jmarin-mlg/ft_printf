/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:26:12 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/04 18:07:55 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n: The integer to convert.
**
** Returns the string representing the number, or NULL if memory allocation
** fails.
*/
static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static char	*ft_numstr(char *s, unsigned int n, size_t len)
{
	while (n > 0)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_numlen(n);
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (!(res))
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res = ft_numstr(res, n, len);
	return (res);
}
