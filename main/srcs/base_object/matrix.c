#include "../../inc/minirt.h"

void    print_m44(t_mat44 *mat)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        printf("[ ");
        while (j < 4)
        {
            printf("%.3f  ", mat->m44[i][j]);
            j++;
        }
        printf(" ]\n");
        i++;
    }
}

int    assign_value_m44(t_mat44 *mat, double value, int row, int col)
{
    if (row < 0 || row > 3 || col < 0 || col > 3)
    {
        printf("ERROR: assign_value_m44: row or col out of range\n");
        return (1);
    }
    mat->m44[row][col] *= value;

    return (0);
}



// return 1 on error;
int    add_m44(t_mat44 *res, t_mat44 *mat, t_mat44 *mat_2)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            res->m44[i][j] = mat->m44[i][j] + mat_2->m44[i][j];
            j++;
        }
        i++;
    }
    return (0);
}

int     sub_m44(t_mat44 *res, t_mat44 *mat, t_mat44 *mat_2)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            res->m44[i][j] = mat->m44[i][j] - mat_2->m44[i][j];
            j++;
        }
        i++;
    }
    return (0);
}

int     scale_m44(t_mat44 *res, double scale, t_mat44 *mat)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 3)
        {
            if (i == j)
                res->m44[i][j] = mat->m44[i][j] * scale;
            j++;
        }
        i++;
    }
    return (0);
}

int     setzero_m44(t_mat44 *res)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            res->m44[i][j] = 0;
            j++;
        }
        i++;
    }
    return (0); 
}

int     init_tfmat44(t_tfmat *tfmat)
{
    set_indentity_m44(&(tfmat->translate));
    set_indentity_m44(&(tfmat->rotate_x));
    set_indentity_m44(&(tfmat->rotate_y));
    set_indentity_m44(&(tfmat->rotate_z));
    set_indentity_m44(&(tfmat->scale_metrix));
    set_indentity_m44(&(tfmat->mul));
    set_indentity_m44(&(tfmat->fwd));
    set_indentity_m44(&(tfmat->bwd));
}

void print_tfmat(t_tfmat *mat)
{
    printf("translate:\n");
    print_m44(&(mat->translate));
    printf("rotate_x:\n");
    print_m44(&(mat->rotate_x));
    printf("rotate_y:\n");
    print_m44(&(mat->rotate_y));
    printf("rotate_z:\n");
    print_m44(&(mat->rotate_z));
    printf("scale_metrix:\n");
    print_m44(&(mat->scale_metrix));
    printf("mul:\n");
    print_m44(&(mat->mul));
    printf("fwd:\n");
    print_m44(&(mat->fwd));
    printf("bwd:\n");
    print_m44(&(mat->bwd));
}

int   create_m44_from_vector(t_mat44 *res, t_vec3d *v)
{
    int i;
    int j;

    assign_value_m44(res, v->x, 0, 0);
    assign_value_m44(res, v->y, 1, 1);
    assign_value_m44(res, v->z, 2, 2);
    assign_value_m44(res, 1, 3, 3);
    return (0); 
}

int set_indentity_m44(t_mat44 *res)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (i == j)
                res->m44[i][j] = 1;
            else
                res->m44[i][j] = 0;
            j++;
        }
        i++;
    }
    return (0); 
}

int     vector_to_translation(t_mat44 *res, t_vec3d *v)
{
    set_indentity_m44(res);
    assign_value_m44(res, v->x, 0, 3);
    assign_value_m44(res, v->y, 1, 3);
    assign_value_m44(res, v->z, 2, 3);
    return (0);
}

int     vector_to_rotate_z(t_mat44 *res, t_vec3d *v)
{
    set_indentity_m44(res);
    assign_value_m44(res, cos(v->z), 0, 0);
    assign_value_m44(res, -sin(v->z), 0, 1);
    assign_value_m44(res, sin(v->z), 1, 0);
    assign_value_m44(res, cos(v->z), 1, 1);

    return (0);
}

int     vector_to_rotate_y(t_mat44 *res, t_vec3d *v)
{
    set_indentity_m44(res);
    assign_value_m44(res, cos(v->y), 0, 0);
    assign_value_m44(res, sin(v->y), 0, 2);
    assign_value_m44(res, -sin(v->y), 2, 0);
    assign_value_m44(res, cos(v->y), 2, 2);

    return (0);
}

int     vector_to_rotate_x(t_mat44 *res, t_vec3d *v)
{
    set_indentity_m44(res);
    assign_value_m44(res, cos(v->x), 1, 1);
    assign_value_m44(res, -sin(v->x), 1, 2);
    assign_value_m44(res, sin(v->x), 2, 1);
    assign_value_m44(res, cos(v->x), 2, 2);

    return (0);
}

int     vector_to_scale_matrix(t_mat44 *res, t_vec3d *v)
{
    set_indentity_m44(res);
    assign_value_m44(res, v->x, 0, 0);
    assign_value_m44(res, v->y, 1, 1);
    assign_value_m44(res, v->z, 2, 2);

    return (0);
}

int     mul_mat44(t_mat44 *res, t_mat44 *base, t_mat44 *scal)
{
    int i;
    int j;
    int k;
    double sum;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            sum = 0;
            while (k < 4)
            {
                sum += base->m44[i][k] * scal->m44[k][j];
                k++;
            }
            res->m44[i][j] = sum;
            j++;
        }
        i++;
    }
    return (0);
}

// create forward matrix
int   mul_tf_member(t_tfmat *tfmat)
{
    set_indentity_m44(&(tfmat->mul));
    mul_mat44(&(tfmat->fwd), &(tfmat->translate), &(tfmat->scale_metrix));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_x));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_y));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_z));
    return (0);
}

// create backward matrix


// หา inverse matrix ของ t_matt44
// invers = 1/det * adjoint

// 1/det
// หา det mat 44
// - หา det minor matrix ของ mat 44
// det44 = sum({(-1)^(i+j) * mat44[i][j] * det_minor44(mat44, i, j)

// adjoint
// adjoint = transpose(cofactor)
// cofactor[i][j] = (-1)^(i+j) * det_minor44(mat44, i, j)

/// @brief หา det ของ Matrix 3x3
double     det_matrix(t_mat33 *m)
{
    double det;

    det = m->m33[0][0] * m->m33[1][1] * m->m33[2][2] +\
            m->m33[0][1] * m->m33[1][2] * m->m33[2][0] +\
            m->m33[0][2] * m->m33[1][0] * m->m33[2][1] -\
            m->m33[0][2] * m->m33[1][1] * m->m33[2][0] -\
            m->m33[0][1] * m->m33[1][0] * m->m33[2][2] -\
            m->m33[0][0] * m->m33[1][2] * m->m33[2][1];
    return (det);
}
// หา minor matrix ของ mat 4x4 ที่ i,j
int    get_minor_33(t_mat33 *res, t_mat44 *mat, int i, int j)
{
    int row;
    int col;
    int r;
    int c;

    row = -1;
    r = 0;
    while (++row < 4)
    {
        if (row == i)
            continue ;
        col = -1;
        c = 0;
        while (++col < 4)
        {
            if (col == j)
                continue ;
            res->m33[r][c] = mat->m44[row][col];
            c++;
        }
        r++;
    }
    return (0);
}

void print_mat33(t_mat33 *mat)
{
    int i;
    int j;

    i = 0;
    while (i < 3)
    {
        j = 0;
        printf("[ ");
        while (j < 3)
        {
            printf("%.3f  ", mat->m33[i][j]);
            j++;
        }
        printf(" ]\n");
        i++;
    }
}

void    test_minor(t_mat44 *mat)
{
    t_mat33 res;
    int i;
    int j;

    j = 0;
    while (j < 3)
    {
        i = 0;
        while (i < 3)
        {
            get_minor_33(&res, mat, i, j);
            print_mat33(&res);
            printf("det: %f\n", det_matrix(&res));
            printf("\n");
            // printf("det: %f\n", det_matrix(&res));
            i++;
        }
        j++;
    }
}