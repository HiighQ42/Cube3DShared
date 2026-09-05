/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_raycast_dda_step.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:07:49 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 13:19:54 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void advance_ray_x(t_ray *ray)
{
    ray->side_dist.x += ray->delta.x;
}

void advance_ray_y(t_ray *ray)
{
    ray->side_dist.y += ray->delta.y;
}

int next_ray_side(t_ray *ray)
{
    if (ray->side_dist.x < ray->side_dist.y)
        return (SIDE_X);
    return (SIDE_Y);
}

void enter_next_cell(t_ray *ray, int side)
{
    if (side == SIDE_X)
    {
        advance_ray_x(ray);
        ray->map.x += ray->step.x;
    }
    else
    {
        advance_ray_y(ray);
        ray->map.y += ray->step.y;
    }
}

void record_hit_side(t_ray *ray, int side)
{
    if (side == SIDE_X)
        ray->side = SIDE_X;
    else
        ray->side = SIDE_Y;
}