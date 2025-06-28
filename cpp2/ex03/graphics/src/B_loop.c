/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:12:38 by kalipso           #+#    #+#             */
/*   Updated: 2025/03/17 17:40:22 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int			ft_loop(t_data *data);
static void	h_refresh_input_file(t_data *data, time_t time);
int			ft_render_frame(t_data *data, int sublim);
int			calculate_pixel_color(t_data *data, t_calcul_px *c, int sublim);
static int	h_bg_texture(t_data *data, t_calcul_px *calcul);

///////////////////////////////////////////////////////////////////////////////]
// main loop refresh if file is changed
int 	ft_loop(t_data *data)
{
	return (0);
}


///////////////////////////////////////////////////////////////////////////////]
// render simple shadows, uses adjusted by tan angle
// used to render while moving
int	ft_render_frame(t_data *data, int sublim)
{
	int			x;
	int			y;
	double		angleA;
	double		angleB;
	t_calcul_px	c;

	ft_memset(&c, 0, sizeof(t_calcul_px));
	ini_stack(data, &c);
	c.c0 = data->eye.c->O.c0;

	y = -1;
	while (++y < SIZE_SCREEN_Y)
	{
		x = -1;
		angleB = atan((y - SIZE_SCREEN_Y / 2) * data->eye.c->fov_cst);
		while (++x < SIZE_SCREEN_X)
		{
			// printf("doing [%d,%d]\n", x, y);
			c.transparence_depth = 0; 
			c.reflected_depth = 0; 
			angleA = atan((x - SIZE_SCREEN_X / 2) * data->eye.c->fov_cst);
			c.v = combined_quaternion_rotation(&data->eye.c->O, angleA, angleB);
			calculate_pixel_color(data, &c, sublim);
			put_pixel_any_buffer(&data->buffer, x, y, c.mat.argb.r << 16 | c.mat.argb.g << 8 | c.mat.argb.b);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->buffer.img, 0, 0);
	return (0);
}


///////////////////////////////////////////////////////////////////////////////]
// require ray origin (c0), ray vector (v)
// fills calcul.argb with the pixel color shaded of the intersection
int	calculate_pixel_color(t_data *data, t_calcul_px *c, int sublim)
{
	// if (c->print)
	// 	printf(C_412"DEPTH calculate_pixel_color ["RED" %d "RESET"]; transp: %d; mirror: %d\n", c->print - 1, c->transparence_depth, c->transparence_depth);
	if (!ft_find_pixel_colision(data, c, 0, 1))
	{
		if (data->bg_light[0]->texture)
			return (h_bg_texture(data, c));
		c->mat.argb.r = (int)(round(data->bg_light[0]->color.r * data->bg_light[0]->ratio));
		c->mat.argb.g = (int)(round(data->bg_light[0]->color.g * data->bg_light[0]->ratio));
		c->mat.argb.b = (int)(round(data->bg_light[0]->color.b * data->bg_light[0]->ratio));
		return (0);
	}
	// else if (sublim == 3)
	// 	ft_progressive_path_tracer(data, c);
	else if (sublim == 2)
		ft_lighting(data, c, shadow_tracing, sublim);
	else if (sublim == 1)
		ft_lighting(data, c, something_block_the_light, sublim);
	else if (sublim == 0)
		ft_lighting_simple(data, c);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////]
// IF ambient light has a texture, return the correct pixel instead of simple bg color
static int	h_bg_texture(t_data *data, t_calcul_px *calcul)
{
	double	l_θ;
	double	l_ϕ;
	
	l_θ = fmin(1.0, fmax(0.0, atan2(calcul->v.dz, calcul->v.dx)  / (2 * PI) + 0.5));
	l_ϕ = fmin(1.0, fmax(0.0, acos(calcul->v.dy) / PI));

	calcul->mat.argb = return_px_img(data->bg_light[0]->texture, l_θ, l_ϕ);
	return (0);
}