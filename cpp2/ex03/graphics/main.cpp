/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:12:38 by kalipso           #+#    #+#             */
/*   Updated: 2025/03/12 11:30:18 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"
#include "../Point.hpp"

#define HEGIHT 500
#define LENGHT 500
#define MAX_X 10.0

#define COLOR1 0x00ff00ff

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;


typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;

	int		bpp;
	int		ll;
	int		end;
	int		sz_x;
	int		sz_y;
}	t_img;

typedef struct s_data2 {
	void	*mlx;
	void	*win;

	t_img	buffer;

	Point*	A;
	Point*	B;
	Point*	C;
	Point*	P;

}	t_data2;




///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end2(data);

	if (keysym == XK_Delete)
		data->change ^= 1;
	else if (keysym == 0xff08)
		data->change_function = NULL;
	else
		return (0);
	ft_render_frame_multi(data, RENDERING_LVL);
	return (0);
}

// Left Button: 1, Middle Button: 2, Right Button: 3, Scroll Up: 4, Scroll Down: 5
int mouse_clic(int button, int x, int y, void *d)
{
	t_data2 *data = (t_data2 *)d;
	
	if (button == 3) {// Right mouse button
		Point p(Fixed(x), Fixed(y));
		data->P = &p;
	}
	else if (button == 1)
	{
		((t_data*)data)->eye.clic_px_x = x;
		((t_data*)data)->eye.clic_px_y = y;
		((t_data*)data)->in_movement = 1;
	}
	else if (button == 4 || button == 5)
	{
		if (button == 4)
			((t_data*)data)->zoom *= 2;
		else
			((t_data*)data)->zoom /= 2;
		printf(C_411"ZOOMED MOVEMENT: "RED"%.3f\n"RESET, ((t_data*)data)->zoom);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_draw_point_buffer(t_img *buffer, Point& p, unsigned int color) {

}


void	clean_buffer(t_data *data)
{
	int		x;
	int		y;
	char	*dst;
	int		offset;

	y = -1;
	while (++y < SIZE_SCREEN_Y)
	{
		x = -1;
		while (++x < SIZE_SCREEN_X)
		{
			offset = (y * data->buffer.ll + x * (data->buffer.bpp / 8));
			dst = data->buffer.addr + offset;
			*(unsigned int *)dst = 0;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->buffer.img, 0, 0);
}

void	put_pixel_any_buffer(t_img *buff, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	offset = (y * buff->ll + x * (buff->bpp / 8));
	dst = buff->addr + offset;
	*(unsigned int *)dst = color;
}
///////////////////////////////////////////////////////////////////////////////]
// ini
void	initialization(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	ini_mlx(data);
}

static void	ini_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		(put(ERRM"MLX fait de la merde\n"), end(data, 1, 1));
	data->win = mlx_new_window(data->mlx, LENGHT, HEGIHT, "testFixed");
	if (!data->win)
		(put(ERRM"Problem initalisazing mlx (2)\n"), end(data, 1, 1));

	data->buffer.img = mlx_new_image(data->mlx, LENGHT, HEGIHT);
	if (!data->buffer.img)
		(put(ERRM"Problem initializing buffer\n"), end(data, 1, 1));
	data->buffer.addr = mlx_get_data_addr(data->buffer.img, &data->buffer.bpp, &data->buffer.ll, &data->buffer.end);
	clean_buffer(&data->buffer);

	mlx_loop_hook(data->mlx, &ft_loop, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, &mouse_clic, data);
	mlx_hook(data->win, 17, 0, &end2, data);
}
///////////////////////////////////////////////////////////////////////////////]
int	main( void ) {
	t_data	data;

	initialization(&data);
	mlx_loop(data.mlx);

	end(&data, 0, 1);
	return (0);
}
