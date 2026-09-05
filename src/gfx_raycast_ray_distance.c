/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_raycast_ray_distance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:23:39 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 12:42:39 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

double next_x_gap(t_vec position, t_vec ray_dir)
{
    double fraction;

    fraction = position.x - floor(position.x);
    if (ray_dir.x < 0.0)
        return (fraction);
    return (1.0 - fraction);
}

double next_y_gap(t_vec position, t_vec ray_dir)
{
    double fraction;

    fraction = position.y - floor(position.y);
    if (ray_dir.y < 0.0)
        return (fraction);
    return (1.0 - fraction);
}

double boundry_distance(double gap, double component)
{
    if (fabs(component) < EPSILON)
        return (RAY_FAR);
    return (gap / fabs(component));
}

double delta_x(t_vec ray_dir)
{
    if (fabs(ray_dir.x) < EPSILON)
        return (RAY_FAR);
    return (fabs(1.0 / ray_dir.x));
}

double delta_y(t_vec ray_dir)
{
    if (fabs(ray_dir.y) < EPSILON)
        return (RAY_FAR);
    return (fabs(1.0 / ray_dir.y));
}