/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_camera_camera_plane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:40:51 by nhamad            #+#    #+#             */
/*   Updated: 2026/09/05 11:42:52 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_vec make_camera_plane(t_vec direction, double scale)
{
    t_vec plane;

    plane.x = -direction.y * scale;
    plane.y = direction.x * scale;
    return (plane);
}