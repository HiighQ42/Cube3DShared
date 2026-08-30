/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:44:59 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 09:54:19 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void draw_background(t_image *image , int ceiling, int floor)
{
    t_point point;
    int color;

    point.y = 0;
    while (point.y < image->height)
    {
        color = ceiling;
        if (point.y >= image->height / 2)
            color = floor;
        point.x = 0;
        while (point.x < image->width)
        {
            write_pixel(image, point, color);
            point.x++;
        }
        point.y++;
    }
}