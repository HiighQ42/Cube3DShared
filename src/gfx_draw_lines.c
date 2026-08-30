/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:06:43 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 09:32:24 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void draw_hline(t_image *image, t_line line, int color)
{
    t_point point;
    int temp;

    if (line.start > line.end)
    {
        temp = line.start;
        line.start = line.end;
        line.end = temp;
    }
    point.x = line.start;
    point.y = line.fixed;
    while (point.x <= line.end)
    {
        write_pixel(image, point, color);
        point.x++;
    }
}

void draw_vline(t_image *image, t_line line, int color)
{
    t_point point;
    int temp;
    
    if (line.start > line.end)
    {
        temp = line.start;
        line.start = line.end;
        line.end = temp;
    }
    point.x = line.fixed;
    point.y = line.start;
    while (point.y <= line.end)
    {
        write_pixel(image, point, color);
        point.y++;
    }
}