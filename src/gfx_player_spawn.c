/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_player_spawn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:35:31 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 11:46:18 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int is_spawn(char cell)
{
    return (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E');
}

int find_spawn(t_Data *scene, t_spawn *spawn)
{
    int x;
    int y;
    char cell;
    
    y = 0;
    while (scene->map.map[y] != NULL)
    {
        x = 0;
        while (scene->map.map[y][x] != '\0')
        {
            cell = scene->map.map[y][x];
            if (is_spawn(cell))
            {
                spawn->x = x;
                spawn->y = y;
                spawn->orientation = cell;
                scene->map.map[y][x] = '0';
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}