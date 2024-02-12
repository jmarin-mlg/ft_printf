/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 07:38:17 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:29:25 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function converts the initial portion of the string pointed to by str to
** int representation.
** ASCII 9 - 13 and 32 => Spaces
** ASCII 43 and 45     => Signs + and -
** ASCII 48 - 57       => Numbers 0 - 9
*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	sign_count;
	int	result;
	int	i;

	sign = 1;
	sign_count = 0;
	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		++i;
	while (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			sign *= -1;
		++i;
		++sign_count;
		if (sign_count >= 2)
			return (0);
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}
