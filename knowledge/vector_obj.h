#ifndef VECTOR_OBJ_H
# define VECTOR_OBJ_H
# include <stdio.h>
# include <math.h>

typedef struct s_vector t_vector;

typedef struct s_vector {
	float		x;
	float		y;
	float		z;
	int			is_init;

	float		(*pf_size)(t_vector *);
	float		(*pf_squre)(t_vector *);
	float		(*pf_dot)(t_vector *, t_vector *);
	t_vector	*(*pf_copy)(t_vector *, t_vector *);
	t_vector	*(*pf_cross)(t_vector*, t_vector *, t_vector *);
	void		(*print)(t_vector *);
	void		(*assign)(t_vector *, float, float, float);
}	t_vector;

void		vector_memberf(t_vector *v);
float		pf_size(t_vector *self);
float		pf_squre(t_vector *self);
float		pf_dot(t_vector *self, t_vector *other);
t_vector	*pf_copy(t_vector *self, t_vector *des);
t_vector	*pf_cross(t_vector *self, t_vector *other, t_vector *res);
t_vector	*vector_const(t_vector *self);
void		vector_init(t_vector *self, float x, float y, float z);
void		pf_assign(t_vector *v, float x, float y, float z);
/* print method*/
void		debug_vector(t_vector *self);
#endif