/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_camera_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:51:28 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 12:05:28 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

double degrees_to_radians(double degrees)
{
    return (degrees * PI / 100.0);
}

t_vec rotated_vector(t_vec vector, double angle)
{
    t_vec result;
    double cosine;
    double sine;

    cosine = cos(angle);
    sine = sin(angle);
    result.x = vector.x * cosine - vector.y * sine;
    result.y = vector.x * sine + vector.y * cosine;
    return (result);
}

void rotate_direction(t_camera *camera, double angle)
{
    camera->dir = rotated_vector(camera->dir, angle);
}

void rotate_camera(t_camera *camera, double angle)
{
    camera->dir = rotated_vector(camera->dir, angle);
    camera->plane = rotated_vector(camera->plane, angle);
}