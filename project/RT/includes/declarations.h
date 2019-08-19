/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik-prog <lyahasik-prog@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:19:34 by dhorker           #+#    #+#             */
/*   Updated: 2019/08/16 20:30:19 by lyahasik-pr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H

# define DECLARATIONS_H

# include "classes.h"

double			ft_vec3_len(t_vec3 vec);
double			ft_vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3			ft_vec3_div_scal(t_vec3 vec, double scal);
t_vec3			ft_vec3_multi_scal(t_vec3 vec, double scal);
t_vec3			ft_vec3_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3			ft_vec3_sum(t_vec3 vec1, t_vec3 vec2);
double			ft_vec3_dist(t_vec3 v1, t_vec3 v2);
t_vec3			ft_vec3_normal(t_vec3 vec);
double			ft_vec3_angle(t_vec3 v1, t_vec3 v2);
unsigned int	ft_vec3_color(t_vec3 vec);
t_vec3			create_vec3(double x, double y, double z);

int				mouse_press(int button, int x, int y, t_scene *scene);
int				key_press(int code, t_scene *scene);
int				ft_close(void *param);

double			check_sphere(t_object *object, t_vec3 pos, t_vec3 dir);
double			check_plane(t_object *object, t_vec3 inter, t_vec3 dir, char shadow);

t_camera		**create_camera();
t_light			**create_light();
t_object		**create_object();
void			create_scene(t_scene *scene);
void			filling_img(t_project *project);
void			direction_camera(t_project *project, double x, double y);

t_vec3			ray_trace(t_project project);
double			intersection(t_scene *scene, t_vec3 inter, t_vec3 dir);
double			create_lighting(t_scene scene, t_vec3 inter, t_vec3 normal);

void			destroy_program(t_project *project);
void			render_show(t_project *project);
void			create_window(t_project *project);
void			catching_events(t_project *project);
void			import_img(const char *str, t_project *project);
unsigned char	*create_texture(const char *str, t_sdl_img *img);

#endif
