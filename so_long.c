/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:11:15 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/02/21 02:17:06 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>


#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// int main(void)
// {
//     void    *mlx_ptr;
//     void    *mlx_win;

//     mlx_ptr = mlx_init();
//     mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window");
//     int x = 0;
//     int y = 0;
//     int i = 0;
//     while (i < RECTANGLE_HEIGHT)
//     {
//         int j = 0;
//         while (j < RECTANGLE_WIDTH)
//         {
//             mlx_pixel_put(mlx_ptr, mlx_win, x + j, y + i, RED_PIXEL);
//             j++;
//         }
//         i++;
//     }
//     mlx_loop(mlx_ptr);
//     mlx_destroy_window(mlx_ptr, mlx_win);
//     return (0);
// }


int handel_input(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);   
    }
    return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}



int main(void)
{
    t_data  data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (0);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Test");    
    if (data.win_ptr == NULL)
        return (0);
    mlx_key_hook(data.win_ptr, &handel_input, &data);
    data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/img.xpm", &data.img.img_width, &data.img.img_height);
    int x = 0;
    while (x < WINDOW_WIDTH) {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, x, 0);
        x += data.img.img_width;
    }
    x = 0;
    while (x < WINDOW_WIDTH) {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, x, WINDOW_HEIGHT - data.img.img_height);
        x += data.img.img_width;
    }
    int y = data.img.img_height;
    while (y < WINDOW_HEIGHT - data.img.img_height) {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, y);
        y += data.img.img_height;
    }
    y = data.img.img_height;
    while (y < WINDOW_HEIGHT - data.img.img_height) {
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, WINDOW_WIDTH - data.img.img_width, y);
        y += data.img.img_height;
    }
    mlx_loop(data.mlx_ptr);
}

