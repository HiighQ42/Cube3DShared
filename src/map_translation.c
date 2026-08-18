/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:58:07 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 19:26:19 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	make_map(t_Data *data, t_prelist *head)
{
	data->map.size = count_map_size(head);
	if (data->map.size < 0)
		return (-1);
	data->map.map = (char **)ft_calloc(data->map.size + 1, sizeof(char *));
	if (!data->map.map)
		return (-1);
	return (map_copy(data->map, head));
}

int	count_map_size(t_prelist *list)
{
	int	size;

	size = 0;
	while (list && ft_strncmp(list->contents, "\n", ft_strlen(list->contents)))
	{
		size++;
		list = list->next;
	}
	if (list && skip_to_last(list))
		return (-1);
	return (size);
}

int	map_copy(t_MapContent node, t_prelist *list)
{
	int	i;

	i = 0;
	while (i < node.size)
	{
		node.map[i] = ft_strtrim(list->contents, "\n");
		if (!node.map[i])
			return (free_map_reverse(node.map, i), -1);
		i++;
		list = list->next;
	}
	node.map[node.size] = NULL;
	return (0);
}

void	free_map_reverse(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
}
