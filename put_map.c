/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:10:19 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/08 21:52:56 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	add_pixel(int x, int y, int z, t_add *node)
{
	t_pixel	pixel;

	pixel.dim3.x = x * node->zoom;
	pixel.dim3.y = y * node->zoom;
	pixel.dim3.z = z * node->z_ampl;
	pixel.dim2.x = deal_with_x(pixel.dim3.x, pixel.dim3.y, pixel.dim3.z) +
		node->offsetx;
	pixel.dim2.y = deal_with_y(pixel.dim3.x, pixel.dim3.y, pixel.dim3.z, node)
		+ node->offsety;
	return (pixel);
}

static void		draw_line(t_pixel pixel1, t_pixel pixel2, t_add *node)
{
	int		dx;
	int		dy;
	double	x;
	int		y;

	x = pixel1.dim2.x;
	dx = pixel2.dim2.x - pixel1.dim2.x;
	dy = pixel2.dim2.y - pixel1.dim2.y;
	pixel1.color = add_color(pixel1.dim3.z, pixel2.dim3.z);
	while (x < pixel2.dim2.x)
	{
		y = pixel1.dim2.y + dy * (x - pixel1.dim2.x) / dx;
		mlx_pixel_put(node->mlx, node->win, x, y, pixel1.color);
		x += 0.3;
	}
}

static void		get_pixel(t_lst *ptr, t_add *node, int x, int y)
{
	t_pixel	pixel[2];

	pixel[0] = add_pixel(x, y, ptr->tab[x], node);
	if (x + 1 < ptr->tablen)
	{
		pixel[1] = add_pixel(x + 1, y, ptr->tab[x + 1], node);
		draw_line(pixel[0], pixel[1], node);
	}
	if (ptr->next)
	{
		pixel[1] = add_pixel(x, y + 1, ptr->next->tab[x], node);
		draw_line(pixel[0], pixel[1], node);
	}
}
void		put_map_on_window(t_lst *ptr, t_add *node)
{
	t_lst	*tmp;
	int		x;
	int		y;

	tmp = ptr;
	y = 0;
	while (ptr)
	{
		x = 0;
		while (x < ptr->tablen)
		{
			get_pixel(ptr, node, x, y);
			x++;
		}
		y++;
		ptr = ptr->next;
	}
	ptr = tmp;
}
