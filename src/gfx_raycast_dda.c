/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_raycast_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:20:20 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 13:30:01 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int cell_is_wall(t_Data *scene, t_point cell)
{
    char **map;

    if (scene == NULL || cell.x < 0 || cell.y < 0)
        return (1);
    map = scene->map.map;
    if (cell.y >= scene->map.size || map[cell.y] == NULL)
        return (1);
    if (map[cell.y][cell.x] == '\0' || map[cell.y][cell.x] == ' ')
        reurn (1);
    return (map[cell.y][cell.x] == '1');
}

int run_dda(t_ray *ray, t_Data *scene)
{
    int side;
    int steps;

    steps = 0;
    while (steps < 4096)
    {
        side = next_ray_side(ray);
        enter_next_cell(ray, side);
        if (cell_is_wall(scene, ray->map))
        {
            record_hit_side(ray, side);
            return (1);
        }
        steps++;
    }
    return (0);
}

