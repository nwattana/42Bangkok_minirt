#include  "./vector_obj.h"
#include <math.h>

/// @brief return size of vector 
float pf_size(t_vector *self)
{
	double res;

	res = (double)self->pf_squre(self);
	res = (float)sqrt(res);
	return (res);
}

/// @brief return size's squre of each axis
float pf_squre(t_vector *self)
{
	return (self->x * self->x + \
		self->y * self->y + \
		self->z * self->z);
}

/// @brief init member function and assign value to vector self 
void vector_init(t_vector *self, float x, float y, float z)
{
	self->x = x;
	self->y = y;
	self->z = z;
	self->is_init = 1;
	vector_memberf(self);
}

/// @brief init vector with 0, 0, 0
/// @param self 
/// @return 
t_vector	*vector_const(t_vector *self)
{
	vector_init(self, 0, 0, 0);
	return (self);
}

/// @brief Assign memberfunction to self
/// @param self 
void	vector_memberf(t_vector *self)
{
	self->pf_size = pf_size;
	self->pf_squre = pf_squre;
	self->pf_copy = pf_copy;
	self->pf_dot = pf_dot;
	self->pf_cross = pf_cross;
	self->print = debug_vector;
	self->assign = pf_assign;
}

/// @brief Copy i, j, k to destination
/// @return destination vector
t_vector *pf_copy(t_vector *self, t_vector *des)
{
	vector_init(des, self->x, self->y, self->z);
	
	return (des);
}

/// @brief dot product of self and other 
/// @return dot product result
float pf_dot(t_vector *self, t_vector *other)
{
	return ((self->x * other->x) + (self->y * other->y) + (self->z * other->z));
}

/// @brief cross product of vector self and other, need allocate memory to res first
/// @param res allocated memory address for result of dot product 
/// @return res address
t_vector	*pf_cross(t_vector *self, t_vector *other, t_vector *res)
{
	t_vector temp;

	vector_init(&temp, 0,0,0);
	temp.x = self->y * other->z - other->y * self->z;
	temp.y = self->z * other->x - other->z * self->x;
	temp.z = self->x * other->y - other->x * self->y;
	temp.pf_copy(&temp, res);

	return (res);
}

/// @brief just print
void	debug_vector(t_vector *v)
{
	printf("{ %.2fi, %.2fj, %.2fk } is_init %d\n", v->x, v->y, v->z, v->is_init);
}

/// @brief assign x, y, z to vector
void	pf_assign(t_vector *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
