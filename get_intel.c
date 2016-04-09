/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:32:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/09 17:58:05 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_tablen(t_lst *ptr)
{
	t_lst	*tmp;

	tmp = ptr;
	while (ptr->next)
	{
		if (ptr->tablen != ptr->next->tablen)
		{
			ptr = tmp;
			return (1);
		}
		else
			ptr = ptr->next;
	}
	ptr = tmp;
	return (0);
}

int		get_max_width(t_lst *ptr)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = ptr;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	ptr = tmp;
	return (i);
}

int		deal_with_x(int x, int y, int z)
{
	t_pixel pixel;

	z = 0;
	pixel.dim2.x = x + y;
	return (pixel.dim2.x);
}

int		deal_with_y(int x, int y, int z, t_add *node)
{
	t_pixel	pixel;

	pixel.dim2.y = (y * node->pers) - (node->pers * (x + z));
	return (pixel.dim2.y);
}

int		add_color(int z1, int z2)
{
	if (z1 > 0 && z2 > 0)
		return (0x63e5e7);
	else if (z1 > 0 || z2 > 0)
		return (0xa1d700);
	else if (z1 < 0 && z2 < 0)
		return (0xeb4457);
	else if (z1 < 0 || z2 < 0)
		return (0xec720d);
	return (0xFFFFFF);
}
