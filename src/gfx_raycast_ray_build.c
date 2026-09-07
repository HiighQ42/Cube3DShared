/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_raycast_ray_build.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:06:41 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 19:59:18 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int valid_column(int x, int width)
{
    if (width <= 0 || x < 0 || x >= width)
        return (0);
    return (1);
}

double camera_position(int x, int width)
{
    double pixel_center;

    if (!valid_column(x, width))
        return (0.0);
    pixel_center = (double)x + 0.5;
    return (2.0 * pixel_center / (double)width - 1.0);
}

t_vec ray_direction(t_camera *camera, double camera_x)
{
    t_vec direction;

    direction.x = camera->dir.x + camera->plane.x * camera_x;
    direction.y = camera->dir.y + camera->plane.y * camera_x;
    return (direction);
}

void print_ray_sample(int x, double camera_x, t_vec ray_dir)
{
    printf("column=%d camera_x=%.4f ray =(%.4f, %.4f)\n", x, camera_x, ray_dir.x, ray_dir.y);
}

t_point ray_map_cell(t_vec position)
{
    t_point cell;

    cell.x = (int)floor(position.x);
    cell.y = (int)floor(position.y);
    return (cell);
}
