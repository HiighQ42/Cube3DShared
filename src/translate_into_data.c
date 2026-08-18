/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_into_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:05:15 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 19:28:21 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"

t_Data	*translate_into_data(t_prelist *list)
{
	t_Data	*ret;
	char	**tmp;

	ret = ft_calloc(1, sizeof(t_Data));
	if (!ret)
		return (NULL);
	make_index_strings(ret->info.index_element);
	while (list && ret->info.element_counter != 6)
	{
		tmp = ft_split(list->contents, ' ');
		if (!tmp)
			return (NULL);
		if (ft_strncmp(tmp[0], "\n", ft_strlen(tmp[0])))
		{
			if (arrays_to_data(ret, tmp))
				return (free_tab(tmp), free_data(ret), NULL);
		}
		free_tab(tmp);
		list = list->next;
	}
	list = skip_to_map(list);
	if (make_map(ret, list))
		return (free_data(ret), NULL);
	return (ret);
}

// void	print_info(t_Data *data)
// {
// 	for (int i = 0; i < 4; i++)
// 		printf("Textid: %s and Path: %s\n",
// 			data->info.index_element[data->texture[i].typeid],
// 			data->texture[i].path);
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("Colorid: %s\n",
// 			data->info.index_element[data->color[i].typeid]);
// 		printf("Colorrange: %i, %i, %i\n", data->color[i].range[0],
// 			data->color[i].range[1], data->color[i].range[2]);
// 	}
// 	printf("size: %i\n", data->map.size);
// 	for (int i = 0; data->map.map[i]; i++)
// 		printf("line %i: %s  len:%zu\n", i, data->map.map[i],
// 			ft_strlen(data->map.map[i]));
// }
