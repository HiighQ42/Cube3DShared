/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:08:00 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 16:44:37 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_map(t_MapContent *data)
{
	t_Parse	*pdata;

	pdata = (t_Parse *)ft_calloc(1, sizeof(t_Parse));
	if (!pdata)
		return (error_message(2), -1);
	if (prep_pdata(data, pdata))
		return (free(pdata), -1);
	if (char_in_map(pdata->copy))
		return (free_tab(pdata->copy), free(pdata), -1);
	if (flood_fill(pdata))
		return (free_tab(pdata->copy), free(pdata), -1);
	return (free_tab(pdata->copy), free(pdata), 0);
}
