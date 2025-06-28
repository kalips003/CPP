/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_builtin_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:12:38 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/16 04:12:38 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

///////////////////////////////////////////////////////////////////////////////]
// void	f_rotation_mouse_slide_the_buffer(t_calcul_px *calcul, )


// c->v = calc_angle_view(data->eye.c, x - SIZE_SCREEN_X / 2, y - SIZE_SCREEN_Y / 2);
// x between [-screenX/2, screenX/2] 
t_vect	calc_angle_view(t_camera *cam, int x, int y)
{
	t_vect	rtrn;
	double	cx;
	double	cy;

	cx = x * cam->fov_cst;
	cy = -y * cam->fov_cst;
	rtrn = cam->O.view;
	rtrn = (t_vect){
		rtrn.dx + cx * cam->O.right.dx + cy * cam->O.up.dx,
		rtrn.dy + cx * cam->O.right.dy + cy * cam->O.up.dy,
		rtrn.dz + cx * cam->O.right.dz + cy * cam->O.up.dz,
	};
	ft_normalize_vect(&rtrn);
	return (rtrn);
}

