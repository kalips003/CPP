/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_general_struct.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:55:43 by marvin            #+#    #+#             */
/*   Updated: 2025/03/11 16:14:33 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_GENERAL_STRUCT_H
# define MINIRT_GENERAL_STRUCT_H

///////////////////////////////////////////////////////////////////////////////]
// 
// 			█▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ 　 █▀▀ ▀▀█▀▀ █▀▀█ █░░█ █▀▀ ▀▀█▀▀ 
// 			█░░█ █▄▄█ ░░█░░ █▄▄█ 　 ▀▀█ ░░█░░ █▄▄▀ █░░█ █░░ ░░█░░ 
// 			▀▀▀░ ▀░░▀ ░░▀░░ ▀░░▀ 　 ▀▀▀ ░░▀░░ ▀░▀▀ ░▀▀▀ ▀▀▀ ░░▀░░
//
///////////////////////////////////////////////////////////////////////////////]

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_argb;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
}	t_coor;

typedef struct s_vect
{
	double	dx;
	double	dy;
	double	dz;
}	t_vect;

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

////////////////////////////////////////////]
typedef struct s_param
{
	t_argb	argb;
	
	double	specular;
	double	shiny;
	double	mirror;
	double	transparence;
	double	gamma;
	double	light;
	
	t_rgb	color2;
	t_img	*texture;
	t_img	*normal_map;
	t_img	*alpha_map;

}	t_param;//		objects param

typedef struct s_param2
{
	t_argb	argb;
	
	double	sp;
	double	sh;
	double	mi;
	double	tr;
	double	gamma;
	double	light;

	char	*name;

}	t_mat;//		objects param

typedef struct s_obj
{
	t_coor		c0;
	t_vect		view;
	t_vect		up;
	t_vect		right;

}	t_obj;

typedef struct s_obj2
{
	int		type;
	t_obj	O;
	t_param	param;
	// t_model	*model;

}	t_obj2;//		default object

////////////////////////////////////////////]
// MODELS
////////////////////////////////////////////]
typedef struct s_tri
{
	
	int		p1;
	int		vt1;
	int		vn1;
	int		p2;
	int		vt2;
	int		vn2;
	int		p3;
	int		vt3;
	int		vn3;
	
	
	
	// t_coor		*p1;
	// t_coor		*p2;
	// t_coor		*p3;
	// t_vect		*vn1;
	// t_vect		*vn2;
	// t_vect		*vn3;
	// t_vt		*vt1;
	// t_vt		*vt2;
	// t_vt		*vt3;

	t_mat		*mat;
	struct s_tri	*next;
}	t_tri;

typedef struct s_vt
{
	double	u;
	double	v;
}	t_vt;


typedef struct s_model
{
	t_coor	**v;
	t_vect	**vn;
	t_vt	**vt;
	t_mat	**mat;
	t_tri	*f;
	t_tri	*first;
	t_coor	min;
	t_coor	max;
	char	*path;
}	t_model;

// MODEL
typedef struct s_object
{
	int		type;
	t_obj	O;
	t_param	param;
	
	t_model	*model;
	double	size;
}	t_object;

#endif