/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 21:00:25 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/08 22:04:28 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_with_arg(int argc, char **argv, int fd)
{
	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./fdf <filename>", 2);
		exit (0);
	}
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			perror(argv[1]);
			exit (0);
		}
	}
	return (fd);
}

void	push_node(t_lst *node, t_lst **head)
{
	t_lst *tmp;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_lst	*init_lst(t_lst *ptr, char *line)
{
	int		i;
	int		tab_len;

	tab_len = 0;
	if (!(ptr = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
	ptr->next = NULL;
	ptr->str = ft_strsplit(line, ' ');
	tab_len = ft_tablen(ptr->str);
	ptr->tab = malloc(sizeof(int) * (tab_len));
	i = 0;
	while (ptr->str[i])	
	{
		ptr->tab[i] = ft_atoi(ptr->str[i]);
		i++;
	}
	ptr->tablen = i;
	return (ptr);
}


t_lst	*get_map(t_lst *ptr, int fd)
{
	t_lst	*head;
	char	*line;
	int		y;
	
	line = NULL;
	head = NULL;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ptr = init_lst(ptr, line);
		push_node(ptr, &head);
		y++;
	}
	return (head);
}


int		main(int argc, char **argv)
{
	int		fd;
	t_lst	*ptr;
	t_add	*node;

	fd = 0;
	ptr = NULL;
	fd = deal_with_arg(argc, argv, fd);	
	ptr = get_map(ptr, fd);
	node = init_add(ptr);
	open_window(ptr, node);
	close(fd);
	return (0);
}
