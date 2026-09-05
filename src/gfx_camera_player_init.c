/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_camera_player_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:01:48 by nhamad            #+#    #+#             */
/*   Updated: 2026/08/30 12:07:22 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_vec start_direction(char orientation)
{
    t_vec direction;
    
    direction.x = 1.0;
    direction.y = 0.0;
    if (orientation == 'N')
    {
        direction.x = 0.0;
        direction.y = -1.0;
    }
    if (orientation == 'S')
    {
        direction.x = 0.0;
        direction.y = 1.0;
    }
    if (orientation == 'W')
    {
        direction.x = -1.0;
        direction.y = 0.0;
    }
    return (direction);
}