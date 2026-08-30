#include "graphics.h"
void draw_vector(t_image *image, t_vec origin, t_vec vector, int color)
{
    t_vec current;
    t_vec step;
    t_point point;
    int i;
    int count;
    count = 32;
    step.x = vector.x / count;
    step.y = vector.y / count;
    current = origin;
    i = 0;
    while (i <= count)
    {
        point.x = (int)current.x;
        point.y = (int)current.y;
        write_pixel(image, point, color);
        current.x += step.x;
        current.y += step.y;
        i++;
    }
}