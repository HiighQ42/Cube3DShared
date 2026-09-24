/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:39:07 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/15 18:53:24 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_data(t_Data *data)
{
	if (!data)
		return ;
	free_map(data->map);
	free_texture(data->texture);
	free(data);
}

void	free_texture(t_Texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (texture[i].path)
			free(texture[i].path);
		i++;
	}
}

void	free_map(t_MapContent node)
{
	int	i;

	if (!node.map)
		return ;
	i = 0;
	while (node.map[i])
	{
		free(node.map[i]);
		i++;
	}
	free(node.map);
}
