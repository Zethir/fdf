/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:31:54 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/08 22:44:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_lst(t_lst *ptr)
{
	t_lst	*next;

	while (ptr)
	{
		next = ptr->next;
		if (ptr->str)
			ft_strdel(ptr->str);
		if (ptr->tab)
			free(ptr->tab);
		free(ptr);
		ptr = next;
	}
	ptr = NULL;
}

t_add		*init_add(t_lst *ptr)
{
	t_add	*node;

	if (!(node = (t_add *)malloc(sizeof(t_add))))
		return (NULL);
	node->z_ampl = 5;
	node->offsetx = 210;
	node->offsety = 530;
	node->max_width = get_max_width(ptr);
	node->max_len = ptr->tablen;
	node->zoom = 1000 / (((node->max_len + node->max_width) / 2) * 3);
	node->pers = 0.5;
	return (node);
}
