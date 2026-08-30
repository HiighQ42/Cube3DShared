/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:33:10 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 09:39:06 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void fill_rect(t_image *image, t_rect rect, int color)
{
    t_point point;
    
    point.y = rect.y;
    while (point.y < rect.y + rect.height)
    {
        point.x = rect.x;
        while (point.x < rect.x + rect.width)
        {
            write_pixel(image, point, color);
            point.x++;
        }
        point.y++;
    }
}