#include  "vector_obj.h"

int main(void)
{
	float x = 1;
	float y = 1;
	float z = 1;
	t_vector v;
	t_vector v2;
	t_vector v3;

	vector_init(&v, x, y, z);
	printf("%f\n", v.pf_size(&v));
	v.pf_copy(&v, &v2);
	printf("%f\n", v2.pf_size(&v2));
	printf("%f\n", v.pf_dot(&v, &v2));
	debug_vector(&v);
	debug_vector(&v2);
	v.pf_cross(&v, &v2, &v2);
	v2.print(&v2);
	vector_const(&v3);
	v3.assign(&v3, 1, 2, 3);
	v3.print(&v3);
	printf("%ld, %ld, %ld, %ld, %ld\n",sizeof(unsigned char), sizeof(float), sizeof(pf_assign), sizeof(pf_cross), sizeof(t_vector));
}