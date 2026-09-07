/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_projection_math.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:25:49 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/07 14:06:36 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

double project_depth(double ray_length, double angle_offset)
{
    return (ray_length * cos(angle_offset));
}

double wall_distance(t_ray *ray)
{
    if (ray->side == SIDE_X)
        return (ray->side_dist.x - ray->delta.x);
    return (ray->side_dist.y - ray->delta.y);
}

int wall_height(double distance, int screen_heigt)
{
    int height;

    if (distance < EPSILON)
        return (screen_heigt);
    height = (int)((double)screen_heigt / distance);
    if (height < 1)
        height = 1;
    return (height);
}

t_span wall_span(int line_height, int screen_height)
{
    t_span span;
    span.start = screen_height / 2-line_height / 2;
    span.end = span.start + line_height - 1;
    return (span);
}

t_span clip_span(t_span span, int screen_height)
{
    t_span clipped;

    clipped = span;
    if (clipped.start < 0)
        clipped.start = 0;
    if (clipped.end >= screen_height)
        clipped.end = screen_height - 1;
    return (clipped);
}