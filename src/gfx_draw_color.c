/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 08:59:18 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 09:04:33 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int make_rgb(t_Color *color)
{
    return ((color->range[0] << 16) | (color->range[1] << 8) | color->range[2]);
}

void fill_image(t_image *image, int color)
{
    t_point point;
    
    point.y = 0;
    while (point.y < image->height)
    {
        point.x = 0;
        while (point.x < image->width)
        {
            write_pixel(image, point, color);
            point.x++;
        }
        point.y++;
    }
}