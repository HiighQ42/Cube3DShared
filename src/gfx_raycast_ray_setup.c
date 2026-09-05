/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_raycast_ray_setup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:52:33 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 13:07:20 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_point ray_step(t_vec ray_dir)
{
    t_point step;

    step.x = 1;
    step.y = 1;
    if (ray_dir.x < 0.0)
        step.x = -1;
    if (ray_dir.y < 0.0)
        step.y = -1;
    return (step);
}

void init_side_dist(t_ray *ray, t_camera *camera)
{
    double x_gap;
    double y_gap;

    x_gap = next_x_gap(camera->pos, ray->dir);
    y_gap = next_y_gap(camera->pos, ray->dir);
    ray->side_dist.x = boundary_distance(x_gap, ray->dir.x);
    ray->side_dist.y = boundary_distance(y_gap, ray->dir.y);
}

void init_ray(t_ray *ray, t_game *game, int x)
{
    double camera_x;

    camera_x = camera_position(x, game->width);
    ray->dir = ray_direction(&game->camera, camera_x);
    ray->map = ray_map_cell(game->camera.pos);
    ray->step = ray_step(ray->dir);
    ray->delta.x = delta_x(ray->dir);
    ray->delta.y = delta_y(ray->dir);
    init_side_dist(ray, &game->camera);
}

