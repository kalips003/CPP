#include "inc/minirt.h"

///////////////////////////////////////////////////////////////////////////////]
static void	ini_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		(put(ERRM"MLX fait de la merde\n"), end(data, 1, 1));
	data->win = mlx_new_window(data->mlx, SIZE_SCREEN_X, SIZE_SCREEN_Y, "TestFixed");
	if (!data->win)
		(put(ERRM"Problem initalisazing mlx (2)\n"), end(data, 1, 1));

	data->buffer.img = mlx_new_image(data->mlx, SIZE_SCREEN_X, SIZE_SCREEN_Y);
	if (!data->buffer.img)
		(put(ERRM"Problem initializing buffers\n"), end(data, 1, 1));
	data->buffer.addr = mlx_get_data_addr(data->buffer.img, &data->buffer.bpp, &data->buffer.ll, &data->buffer.end);

	mlx_loop_hook(data->mlx, &ft_loop, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, &mouse_clic, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask, &mouse_release, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, &mouse_move, data);
	mlx_hook(data->win, 17, 0, &end2, data);
}