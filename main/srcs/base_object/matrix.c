#include "../../inc/minirt.h"

void    print_m44(t_mat44 *mat, char *name)
{
    int i;
    int j;

    i = 0;
    printf("%s\n", name);
    while (i < 4)
    {
        j = 0;
        printf("[ ");
        while (j < 4)
        {
            printf("%.4f  ", mat->m44[i][j]);
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
    mat->m44[row][col] = value;

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
        while (j < 4)
        {
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

int     set_identity_tfmat44(t_tfmat *tfmat)
{
    set_identity_m44(&(tfmat->translate));
    set_identity_m44(&(tfmat->rotate_x));
    set_identity_m44(&(tfmat->rotate_y));
    set_identity_m44(&(tfmat->rotate_z));
    set_identity_m44(&(tfmat->scale_metrix));
    set_identity_m44(&(tfmat->mul));
    set_identity_m44(&(tfmat->fwd));
    set_identity_m44(&(tfmat->bwd));
}

void print_tfmat(t_tfmat *mat)
{
    print_m44(&(mat->translate), "translate");
    print_m44(&(mat->rotate_x), "rotate_x");
    print_m44(&(mat->rotate_y), "rotate_y");
    print_m44(&(mat->rotate_z), "rotate_z");
    print_m44(&(mat->scale_metrix), "scale_metrix");
    print_m44(&(mat->mul), "mul");
    print_m44(&(mat->fwd), "fwd");
    print_m44(&(mat->bwd), "bwd");
}

int set_identity_m44(t_mat44 *res)
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
    set_identity_m44(res);
    assign_value_m44(res, v->x, 0, 3);
    assign_value_m44(res, v->y, 1, 3);
    assign_value_m44(res, v->z, 2, 3);
    return (0);
}

int     vector_to_rotate_z(t_mat44 *res, t_vec3d *v)
{
    set_identity_m44(res);
    assign_value_m44(res, cos(v->z), 0, 0);
    assign_value_m44(res, -sin(v->z), 0, 1);
    assign_value_m44(res, sin(v->z), 1, 0);
    assign_value_m44(res, cos(v->z), 1, 1);

    return (0);
}

int     vector_to_rotate_y(t_mat44 *res, t_vec3d *v)
{
    set_identity_m44(res);
    assign_value_m44(res, cos(v->y), 0, 0);
    assign_value_m44(res, sin(v->y), 0, 2);
    assign_value_m44(res, -sin(v->y), 2, 0);
    assign_value_m44(res, cos(v->y), 2, 2);

    return (0);
}

int     vector_to_rotate_x(t_mat44 *res, t_vec3d *v)
{
    set_identity_m44(res);
    assign_value_m44(res, cos(v->x), 1, 1);
    assign_value_m44(res, -sin(v->x), 1, 2);
    assign_value_m44(res, sin(v->x), 2, 1);
    assign_value_m44(res, cos(v->x), 2, 2);

    return (0);
}

int     vector_to_scale_matrix(t_mat44 *res, t_vec3d *v)
{
    set_identity_m44(res);
    assign_value_m44(res, v->x, 0, 0);
    assign_value_m44(res, v->y, 1, 1);
    assign_value_m44(res, v->z, 2, 2);

    return (0);
}

// SUSPECTED
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

/// @brief หา det ของ Matrix 3x3
double     det_matrix(t_mat33 *m)
{
    double det;

    det = m->m33[0][0] *\
        ( m->m33[1][1] * m->m33[2][2] - \
        m->m33[1][2] * m->m33[2][1]) - \
        m->m33[0][1] * \
        (m->m33[1][0] * m->m33[2][2] - \
        m->m33[1][2] * m->m33[2][0]) + \
        m->m33[0][2] *\
        (m->m33[1][0] * m->m33[2][1] - \
        m->m33[1][1] * m->m33[2][0]);
    return (det);
}
// หา minor matrix ของ mat 4x4 ที่ i,j
int    get_minor_33(t_mat33 *res, t_mat44 *mat, int i, int j)
{
    int row;
    int col;
    int row_res;
    int col_res;

    row = -1;
    row_res = 0;
    while (++row < 4)
    {
        if (row != i)
        {
            col = -1;
            col_res = 0;
            while (++col < 4)
            {
                if (col != j)
                {
                    res->m33[row_res][col_res] = mat->m44[row][col];
                    col_res++;
                }
            }
            row_res++;
        }
    }
    return (0);
}

// print matrix 3x3
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

// test minor matrix ของ mat 4x4
void    test_minor(t_mat44 *mat)
{
    t_mat33 res;
    int i;
    int j;
    double det;

    j = 0;
    while (j < 4)
    {
        i = 0;
        while (i < 4)
        {
            get_minor_33(&res, mat, i, j);
            det = det_matrix(&res);
            i++;
        }
        j++;
    }
}

double  det_matrix44(t_mat44 *mat)
{
    double det;
    t_mat33 res;

    get_minor_33(&res, mat, 0, 0);
    det += pow(-1, 0) * mat->m44[0][0] * det_matrix(&res);
    get_minor_33(&res, mat, 0, 1);
    det += pow(-1, 1) * mat->m44[0][1] * det_matrix(&res);
    get_minor_33(&res, mat, 0, 2);
    det += pow(-1, 2) * mat->m44[0][2] * det_matrix(&res);
    get_minor_33(&res, mat, 0, 3);
    det += pow(-1, 3) * mat->m44[0][3] * det_matrix(&res);
    
    return (det);
}

int     create_cofacto_matrix44(t_mat44 *res, t_mat44 *mat)
{
    t_mat33 minor;
    int     i;
    int     j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            get_minor_33(&minor, mat, i, j);
            res->m44[i][j] = pow(-1, i + j) * det_matrix(&minor);
            j++;
        }
        i++;
    }
}

// Avoid OverLappromble TAT
int     create_cofacto_tranpose(t_mat44 *res, t_mat44 *mat)
{
    int i;
    int j;
    t_mat44 temp;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            temp.m44[i][j] = mat->m44[j][i];
            j++;
        }
        i++;
    }
    ft_memcpy(res, &temp, sizeof(t_mat44));
}


int     cal_tf_matrix(t_tfmat *mat_list, t_input_vector *in)
{
    // init
    vector_to_translation(&(mat_list->translate), &(in->translate));
    vector_to_rotate_x(&(mat_list->rotate_x), &(in->rotate_x));
    vector_to_rotate_y(&(mat_list->rotate_y), &(in->rotate_y));
    vector_to_rotate_z(&(mat_list->rotate_z), &(in->rotate_z));
    vector_to_scale_matrix(&(mat_list->scale_metrix), &(in->scale));

    cal_tfmat_fwd(mat_list);
    cal_tfmat_bwd(mat_list);

    return (SUCCESS);
}

int     cal_tfmat_bwd(t_tfmat *mat_list)
{
    double det;

    det = det_matrix44(&(mat_list->fwd));
    if (almost_equal(det,0))
    {
        debug_message("cal_tfmat_bwd: det = 0");
        exit(ERROR);
    }
    create_cofacto_matrix44(&(mat_list->mul), &(mat_list->fwd));
    create_cofacto_tranpose(&(mat_list->mul), &(mat_list->mul));
    scale_m44(&(mat_list->bwd), 1.0 / det, &(mat_list->mul));

    return (SUCCESS);
}

// create forward matrix call multiply all member save to fwd
int   cal_tfmat_fwd(t_tfmat *tfmat)
{
    set_identity_m44(&(tfmat->mul));
    mul_mat44(&(tfmat->fwd), &(tfmat->translate), &(tfmat->scale_metrix));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_z));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_y));
    mul_mat44(&(tfmat->fwd), &(tfmat->fwd), &(tfmat->rotate_x));

    return (0);
}

int init_tfmat(t_tfmat *tfmat)
{
    set_identity_m44(&(tfmat->translate));
    set_identity_m44(&(tfmat->rotate_x));
    set_identity_m44(&(tfmat->rotate_y));
    set_identity_m44(&(tfmat->rotate_z));
    set_identity_m44(&(tfmat->scale_metrix));
    set_identity_m44(&(tfmat->mul));
    set_identity_m44(&(tfmat->fwd));
    set_identity_m44(&(tfmat->bwd));
    return (0);
}
