/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:38:25 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 19:28:29 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/get_next_line.h"
#include "fcntl.h"

t_Data	*prep_data(char *filename)
{
	t_Data		*ret;
	t_prelist	*list;
	char		*tmp;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	list = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		node_add_back(&list, make_new_node(tmp), fd);
		tmp = get_next_line(fd);
	}
	close(fd);
	if (check_read_result(list))
		return (free_list(list), NULL);
	ret = translate_into_data(list);
	if (!ret)
		return (free_list(list), NULL);
	return (free_list(list), ret);
}
