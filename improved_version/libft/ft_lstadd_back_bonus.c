/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:27 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/04 19:17:38 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** lst: The address of a pointer to the first node of a list.
** new: The pointer to a node to add to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	aux = ft_lstlast(*(lst));
	if (!aux)
		*lst = new;
	else
		aux->next = new;
	return ;
}
