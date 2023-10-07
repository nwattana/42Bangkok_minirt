#include "../../inc/minirt.h"

int	keyhandler(int keycode)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("KEY_A: %s\n", "LEFT");
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("KEY_D: %s\n", "RIGHT");
	if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("KEY_S: %s\n", "DOWN");
	if (keycode == KEY_UP || keycode == KEY_W)
		printf("KEY_W: %s\n", "UP");
    if (keycode == KEY_R)
		printf("KEY_R: %s\n", "R");
    if (keycode == KEY_Q)
        printf("KEY_Q: %s\n", "Q");
    if (keycode == KEY_0)
        printf("KEY_0: %s\n", "0");
    if (keycode == KEY_1)
        printf("KEY_1: %s\n", "1");
    if (keycode == KEY_2)
        printf("KEY_2: %s\n", "2");
    if (keycode == KEY_3)
        printf("KEY_3: %s\n", "3");
    if (keycode == KEY_4)
        printf("KEY_4: %s\n", "4");
    if (keycode == KEY_5)
        printf("KEY_5: %s\n", "5");
    if (keycode == KEY_6)
        printf("KEY_6: %s\n", "6");
    if (keycode == KEY_7)
        printf("KEY_7: %s\n", "7");
    if (keycode == KEY_8)
        printf("KEY_8: %s\n", "8");
    if (keycode == KEY_9)
        printf("KEY_9: %s\n", "9");
    if (keycode == KEY_MINUS)
        printf("KEY_MINUS: %s\n", "MINUS");
    if (keycode == KEY_PLUS)
        printf("KEY_PLUS: %s\n", "PLUS");
    if (keycode == KEY_CTRL)
        printf("KEY_CTRL: %s\n", "CTRL");
    if (keycode == KEY_SHIFT)
        printf("KEY_CTRL: %s\n", "SHIFT");
    if (keycode == KEY_SPACE)
        printf("KEY_SPACE: %s\n", "SPACE");
    if (keycode == KEY_ENTER)
        printf("KEY_ENTER: %s\n", "ENTER");
	if (keycode == KEY_ESC)
		printf("KEY_ESC: %s\n", "EXIT");
	return (0);
}