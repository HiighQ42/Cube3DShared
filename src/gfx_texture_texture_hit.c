/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_texture_texture_hit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:51:39 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 18:01:05 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_vec wall_hit(t_camera *camera, t_ray *ray)
{
    t_vec hit;
    
    hit.x = camera->pos.x + ray->dir.x * ray->distance;
    hit.y = camera->pos.y + ray->dir.y * ray->distance;
    ray->hit = hit;
    return (hit);
}

double wall_fraction(t_vec hit, int side)
{
    double fraction;

    if (side == SIDE_X)
        fraction = hit.y - floor(hit.y);
    else
        fraction = hit.x - floor(hit.x);
    return (fraction);
}

int texture_column(double wall_x, int texture_width)
{
    int column;

    column = (int)(wall_x * (double)texture_width);
    if (column < 0)
        column = 0;
    if (column >= texture_width)
        column = texture_width - 1;
    return (column);
}

int orient_texture_x(int tex_x, int width, t_ray *ray)
{
    if (ray->side == SIDE_X && ray->dir.x > 0.0)
        return (width - tex_x - 1);
    if (ray->side == SIDE_Y && ray->dir.y < 0.0)
        return (width - tex_x - 1);
    return (tex_x);
}