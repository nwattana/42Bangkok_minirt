#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_mat44
{
    double     m44[4][4];
}           t_mat44;

typedef struct s_mat33
{
    double     m33[3][3];
}           t_mat33;

typedef struct s_input_vector
{
    t_vec3d     translate;
    t_vec3d     rotate_x;
    t_vec3d     rotate_y;
    t_vec3d     rotate_z;
    t_vec3d     scale;
}               t_input_vector;

typedef struct s_tfmat
{
    t_mat44     translate;
    t_mat44     rotate_x;
    t_mat44     rotate_y;
    t_mat44     rotate_z;
    t_mat44     scale_metrix;
    t_mat44     mul;
    t_mat44     fwd;
    t_mat44     bwd;
}               t_tfmat;

int     assign_value_m44(t_mat44 *m44, double value, int row, int col);

// Basic matrix operations
int     add_m44(t_mat44 *res, t_mat44 *mat, t_mat44 *mat_2);
int     sub_m44(t_mat44 *res, t_mat44 *mat, t_mat44 *mat_2);
int     scale_m44(t_mat44 *res, double scale, t_mat44 *mat);
int     mul_mat44(t_mat44 *res, t_mat44 *base, t_mat44 *scal);
int     setzero_m44(t_mat44 *res);
int     set_identity_m44(t_mat44 *res);
int     vector_to_translation(t_mat44 *res, t_vec3d *v);
int     vector_to_rotate_z(t_mat44 *res, t_vec3d *v);
int     vector_to_rotate_y(t_mat44 *res, t_vec3d *v);
int     vector_to_rotate_x(t_mat44 *res, t_vec3d *v);
int     vector_to_scale_matrix(t_mat44 *res, t_vec3d *v);
int     mul_mat44(t_mat44 *res, t_mat44 *base, t_mat44 *scal);
double  det_matrix44(t_mat44 *mat);

int     create_cofacto_matrix44(t_mat44 *res, t_mat44 *mat);
int     create_cofacto_tranpose(t_mat44 *res, t_mat44 *mat);

// Main Used
int     cal_tf_matrix(t_tfmat *mat_list, t_input_vector *in);
int     cal_tfmat_fwd(t_tfmat *tfmat);
int     cal_tfmat_bwd(t_tfmat *tfmat);
int     init_tfmat(t_tfmat *tfmat);

int trans_normal_rtxyz(t_vec3d *normal, t_vec3d *rotate_vector);

// DEBUG
void    print_m44(t_mat44 *m44, char *name);
void    print_mat33(t_mat33 *m33);
void    print_tfmat(t_tfmat *mat);
void    test_minor(t_mat44 *mat);

#endif