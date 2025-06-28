/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   K_keypress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:12:38 by kalipso           #+#    #+#             */
/*   Updated: 2025/03/19 17:00:09 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		key_press(int keysym, t_data *data);
int 	mouse_clic(int button, int x, int y, void *data);
int 	mouse_move(int x, int y, void *d);
int 	mouse_release(int button, int x, int y, void *d);
void	print_clic(t_data *data, int x, int y);

///////////////////////////////////////////////////////////////////////////////]
int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end2(data);

	if (keysym == XK_supr)
		data->change ^= 1;
	else if (keysym == 0xff08)
		data->change_function = NULL;
	else
		return (0);
	ft_render_frame_multi(data, RENDERING_LVL);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
// Left Button: 1, Middle Button: 2, Right Button: 3, Scroll Up: 4, Scroll Down: 5
int mouse_clic(int button, int x, int y, void *data)
{
	if (button == 3) // Right mouse button
		print_clic((t_data *)data, x, y);
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
// Left Button: 1, Middle Button: 2, Right Button: 3, Scroll Up: 4, Scroll Down: 5
int mouse_move(int x, int y, void *d)
{
	double	angleA;
	double	angleB;
	int		scalar;
	t_data	*data;
	
	data = (t_data*)d;
	if (data->in_movement && data->eye.clic_px_x != x && data->eye.clic_px_y != y)
	{
		scalar = 1 + !!(data->change_obj) * -3;
		angleA = 1.5 * scalar * (data->eye.clic_px_x - x) * data->eye.c->fov_cst;
		angleB = 1.5 * scalar * (data->eye.clic_px_y - y) * data->eye.c->fov_cst;
		data->eye.c->O.view = combined_quaternion_rotation(&data->eye.c->O, angleA, angleB);
		if (data->change_obj)
			data->eye.c->O.c0 = new_moved_point(&data->change_obj->O.c0, &data->eye.c->O.view, -dist_two_points(&data->eye.c->O.c0, &data->change_obj->O.c0));
		create_vector_space(&data->eye.c->O);
		ft_render_frame_multi(data, RENDER_MOVING_MOUSE);
		data->eye.clic_px_x = x;
        data->eye.clic_px_y = y;
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
int mouse_release(int button, int x, int y, void *d)
{
	double	angleA;
	double	angleB;
	int		scalar;
	t_data	*data;
	
	data = (t_data*)d;
	data->in_movement = 0;
	// if (button == 1 && data->eye.clic_px_x != x && data->eye.clic_px_y != y)
	if (button == 1)
	{
		scalar = 1 + !!(data->change_obj) * -3;
		angleA = 1.5 * scalar * (data->eye.clic_px_x - x) * data->eye.c->fov_cst;
		angleB = 1.5 * scalar * (data->eye.clic_px_y - y) * data->eye.c->fov_cst;
		data->eye.c->O.view = combined_quaternion_rotation(&data->eye.c->O, angleA, angleB);
		if (data->change_obj)
			data->eye.c->O.c0 = new_moved_point(&data->change_obj->O.c0, &data->eye.c->O.view, -dist_two_points(&data->eye.c->O.c0, &data->change_obj->O.c0));
		create_vector_space(&data->eye.c->O);
		ft_render_frame_multi(data, RENDERING_LVL);
	}
	return (0);
}

static const char* g_obj_names[] = {
	"Circle",
	"Sphere",
	"Plane",
	"Cylinder",
	"Cone",
	"Paraboloid",
	"Arrow",
	"Cube",
	"Sprite",
	"Object",
	NULL
};

///////////////////////////////////////////////////////////////////////////////]
void	print_clic(t_data *data, int x, int y)
{
	t_calcul_px c;

	ft_memset(&c, 0, sizeof(t_calcul_px));
	ini_stack(data, &c);
	c.c0 = data->eye.c->O.c0;
	c.print = 1;

	c.v = combined_quaternion_rotation(&data->eye.c->O, atan((x - SIZE_SCREEN_X / 2) * data->eye.c->fov_cst), atan((y - SIZE_SCREEN_Y / 2) * data->eye.c->fov_cst));
	printf(CLEAR);
	printf(C_512"Camera\t[%.1f,%.1f,%.1f\t%.3f,%.3f,%.3f]\n\n", data->eye.c->O.c0.x, data->eye.c->O.c0.y, data->eye.c->O.c0.z, data->eye.c->O.view.dx, data->eye.c->O.view.dy, data->eye.c->O.view.dz);
	printf("\tview \t[% .2f,% .2f,% .2f]\n", data->eye.c->O.view.dx, data->eye.c->O.view.dy, data->eye.c->O.view.dz);
	printf("\tup \t[% .2f,% .2f,% .2f]\n", data->eye.c->O.up.dx, data->eye.c->O.up.dy, data->eye.c->O.up.dz);
	printf("\tright \t[% .2f,% .2f,% .2f]\n", data->eye.c->O.right.dx, data->eye.c->O.right.dy, data->eye.c->O.right.dz);
	printf(C_323"\nMouse clicked at (%d, %d)\tv: [%.3f,%.3f,%.3f]\n", x, y, c.v.dx, c.v.dy, c.v.dz);
	
	// printf(C_244"---------------------------------------------------------\nSTACK PTR: %d\n", c.stack_top);
	// int i = -1;
	// while (++i <= c.stack_top)
	// 	printf(C_405"[%d] %p) γ: %.3f\n", i, c.inside[i], ((t_obj2*)c.inside[i])->param.gamma);
	// printf(C_444"AngleA: %.3f, AngleB: %.3f\n", atan((x - SIZE_SCREEN_X / 2) * data->eye.c->fov_cst), atan((y - SIZE_SCREEN_Y / 2) * data->eye.c->fov_cst));
	printf(C_244"\n-------------------[INSIDE PRINT DATA]-------------------\n");
	calculate_pixel_color(data, &c, PRINT_DEPTH);
	printf(C_244"---------------------------------------------------------\n");

	if (c.object)
	{
		t_obj2 *obj = c.object;
		printf(C_142"\nOBJECT:\t\t%s", g_obj_names[obj->type]);
		printf(C_533"\n\n\txyz \t[%.1f,%.1f,%.1f]\n", obj->O.c0.x, obj->O.c0.y, obj->O.c0.z);
		printf(C_455"\n\tview \t[%.2f,%.2f,%.2f]\n", obj->O.view.dx, obj->O.view.dy, obj->O.view.dz);
		printf("\tup \t[% .2f,% .2f,% .2f]\n", obj->O.up.dx, obj->O.up.dy, obj->O.up.dz);
		printf("\tright \t[% .2f,% .2f,% .2f]\n", obj->O.right.dx, obj->O.right.dy, obj->O.right.dz);
		printf(C_433"\n\tcolor obj\t[%d,%d,%d]\n", obj->param.argb.r, obj->param.argb.g, obj->param.argb.b);
		printf(C_433"\tpx color\t[%d,%d,%d]\n\n", c.mat.argb.r, c.mat.argb.g, c.mat.argb.b);
	}
	printf(C_134"Vector normal surface\t[%.3f, %.3f, %.3f]\n", c.v_normal.dx, c.v_normal.dy, c.v_normal.dz);
	printf("Intersection point\t[%.2f, %.2f, %.2f]\n", c.inter.x, c.inter.y, c.inter.z);
	printf("Distance Intersection\t[%.2f]\n\n", c.dist);

	if (c.object == data->change_obj)
		data->change_obj = NULL;
	else
		data->change_obj = c.object;
	printf(C_440"OBJECT SELECTED %p\n", data->change_obj);
}
