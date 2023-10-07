#include "../../inc/minirt.h"

int camera_translate_minus(t_prog *prog)
{
    t_camera *cam;

    cam = (t_camera *)prog->selected_obj;
    if (prog->sel_axis == ACTIVE_X)
        cam->position.x -= 1;
    if (prog->sel_axis == ACTIVE_Y)
        cam->position.y -= 1;
    if (prog->sel_axis == ACTIVE_Z)
        cam->position.z -= 1;
    re_render(prog);
    return (SUCCESS);
}

int camera_translate_add(t_prog *prog)
{
    t_camera *cam;

    cam = (t_camera *)prog->selected_obj;
    if (prog->sel_axis == ACTIVE_X)
        cam->position.x += 1;
    if (prog->sel_axis == ACTIVE_Y)
        cam->position.y += 1;
    if (prog->sel_axis == ACTIVE_Z)
        cam->position.z += 1;
    re_render(prog);
    return (SUCCESS);
}

int sp_plus_trans(t_prog *prog)
{
    t_sphere *sp;
    t_object *obj;

    obj = prog->cur_obj->content;
    sp = (t_sphere *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        sp->center.x += 1;
    if (prog->sel_axis == ACTIVE_Y)
        sp->center.y += 1;
    if (prog->sel_axis == ACTIVE_Z)
        sp->center.z += 1;
    re_render(prog);
    return (SUCCESS);
}

int sp_minus_trans(t_prog *prog)
{
    t_sphere *sp;
    t_object *obj;

    obj = prog->cur_obj->content;
    sp = (t_sphere *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        sp->center.x -= 1;
    if (prog->sel_axis == ACTIVE_Y)
        sp->center.y -= 1;
    if (prog->sel_axis == ACTIVE_Z)
        sp->center.z -= 1;
    re_render(prog);
    return (SUCCESS);
}

int pl_minus_trans(t_prog *prog)
{
    t_plane *pl;
    t_object *obj;

    printf("Call Handle plane -\n");
    obj = prog->cur_obj->content;
    pl = (t_plane *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        pl->point.x -= 1;
    if (prog->sel_axis == ACTIVE_Y)
        pl->point.y -= 1;
    if (prog->sel_axis == ACTIVE_Z)
        pl->point.z -= 1;
    re_render(prog);
    return (SUCCESS);
}

int pl_plus_trans(t_prog *prog)
{
    t_plane *pl;
    t_object *obj;

    printf("Call Handle plane + \n");
    obj = prog->cur_obj->content;
    pl = (t_plane *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        pl->point.x += 1;
    if (prog->sel_axis == ACTIVE_Y)
        pl->point.y += 1;
    if (prog->sel_axis == ACTIVE_Z)
        pl->point.z += 1;
    re_render(prog);
    return (SUCCESS);
}

int cy_plus_trans(t_prog *prog)
{
    t_cylinder *cy;
    t_object *obj;

    obj = prog->cur_obj->content;
    cy = (t_plane *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        cy->point.x += 1;
    if (prog->sel_axis == ACTIVE_Y)
        cy->point.y += 1;
    if (prog->sel_axis == ACTIVE_Z)
        cy->point.z += 1;
    re_render(prog);
    return (SUCCESS);
}

int cy_minus_trans(t_prog *prog)
{
    t_cylinder *cy;
    t_object *obj;

    obj = prog->cur_obj->content;
    cy = (t_plane *)obj->object;
    if (prog->sel_axis == ACTIVE_X)
        cy->point.x -= 1;
    if (prog->sel_axis == ACTIVE_Y)
        cy->point.y -= 1;
    if (prog->sel_axis == ACTIVE_Z)
        cy->point.z -= 1;
    re_render(prog);
    return (SUCCESS);
}

int select_active_axis(t_prog *prog, int kc)
{
	debug_message("SELECT ACTIVE AXIS\n");
    prog->sel_axis = kc;
    return(SUCCESS);
}

int minus_axis(t_prog *prog)
{
    if (prog->sel_type == CAMERA)
        camera_translate_minus(prog);
    if (prog->sel_type == SPHERE)
        sp_minus_trans(prog);
    if (prog->sel_type == PLANE)
        pl_minus_trans(prog);
    if (prog->sel_type == CYLINDER)
        cy_minus_trans(prog);
    return(SUCCESS);
}

int plus_axis(t_prog *prog)
{
    if (prog->sel_type == CAMERA)
        camera_translate_add(prog);
    if (prog->sel_type == SPHERE)
        sp_plus_trans(prog);
    if (prog->sel_type == PLANE)
        pl_plus_trans(prog);
    if (prog->sel_type == CYLINDER)
        cy_minus_trans(prog);
    return(SUCCESS);
}
