/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:13:28 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/09 18:00:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	do_zoom(int keycode, t_add *node)
{
	if (keycode == 27 || keycode == 78)
		node->zoom -= 1;
	else if (keycode == 24 || keycode == 69)
		node->zoom += 1;
}

static void	add_relief(int keycode, t_add *node)
{
	if (keycode == 116)
		node->z_ampl += 1;
	else if (keycode == 121)
		node->z_ampl -= 1;
}

static void	move_map(int keycode, t_add *node)
{
	if (keycode == 123)
		node->offsetx -= 10;
	if (keycode == 124)
		node->offsetx += 10;
	if (keycode == 126)
		node->offsety -= 10;
	if (keycode == 125)
		node->offsety += 10;
}

int			key_handling(int keycode, t_pack *tmp)
{
	if (keycode == 53)
	{
		free_lst(tmp->ptr);
		exit(0);
	}
	do_zoom(keycode, tmp->node);
	add_relief(keycode, tmp->node);
	move_map(keycode, tmp->node);
	if (keycode == 115)
	{
		if (tmp->node->pers > 0.3)
			tmp->node->pers -= 0.1;
	}
	if (keycode == 119)
	{
		if (tmp->node->pers < 0.8)
			tmp->node->pers += 0.1;
	}
	mlx_clear_window(tmp->node->mlx, tmp->node->win);
	put_map_on_window(tmp->ptr, tmp->node);
	return (0);
}

void		open_window(t_lst *ptr, t_add *node)
{
	t_pack	tmp;

	tmp.ptr = ptr;
	tmp.node = node;
	if (check_tablen(ptr) == 1)
	{
		ft_putendl_fd("Invalid map recieved\n", 2);
		exit(-1);
	}
	node->mlx = mlx_init();
	node->win = mlx_new_window(node->mlx, 1000, 1000, "My fdf");
	put_map_on_window(ptr, node);
	mlx_key_hook(node->win, key_handling, &tmp);
	mlx_loop(node->mlx);
}
