/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 20:23:30 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/08 22:34:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_dim3
{
	int				x;
	int				y;
	int				z;
}					t_dim3;

typedef struct		s_dim2
{
	int				x;
	int				y;
}					t_dim2;

typedef struct		s_pixel
{
	int				color;
	t_dim2			dim2;
	t_dim3			dim3;
}					t_pixel;

typedef struct		s_add
{
	void			*mlx;
	void			*win;
	int				zoom;
	int				z_ampl;
	int				offsetx;
	int				offsety;
	int				max_width;
	int				max_len;
	double			pers;
}					t_add;

typedef	struct		s_lst
{
	void			*mlx;
	void			*win;
	char			**str;
	int				*tab;
	int				zoom;
	int				tablen;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_pack
{
	t_lst			*ptr;
	t_add			*node;
}					t_pack;

t_lst				*get_map(t_lst *ptr, int fd);
t_lst				*init_lst(t_lst *ptr, char *line);
t_add				*init_add(t_lst *ptr);
int					deal_with_arg(int argc, char **argv, int fd);
int					check_tablen(t_lst *ptr);
int					deal_with_x(int x, int y, int z);
int					deal_with_y(int x, int y, int z, t_add *node);
int					add_color(int z1, int z2);
int					get_max_width(t_lst *ptr);
void				push_node(t_lst *node, t_lst **head);
void				open_window(t_lst *ptr, t_add *node);
void				free_lst(t_lst *ptr);
void				put_map_on_window(t_lst *ptr, t_add *node);

#endif
