/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_image_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:00:05 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/18 15:12:57 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

char *pixel_address(t_image *image, t_point point)
{
    int bytes;
    long offset;

    if (image == NULL || image->addr == NULL)
        return (NULL);
    if (point.x < 0 || point.y < 0)
        return (NULL);
    if (point.x >= image->width || point.y >= image->height)
        return (NULL);
    bytes = image->bpp / 8;
    offset = point.y * image->line_len + point.x * bytes;
    return (image->addr + offset);
}

int write_pixel(t_image *image, t_point point, int color)
{
    char *target;
    int bytes;
    int i;
    
    target = pixel_address(image, point);
    if (target == NULL)
        return 0;
    bytes = image->bpp / 8;
    i = 0;
    while (i < bytes)
    {
        if (image->endian == 0)
            target[i] = (color >> (8 * i)) & 255;
        else
            target[bytes - 1 - i] = (color >> (8 * i)) & 255;
        i++;
    }
    return (1);
}