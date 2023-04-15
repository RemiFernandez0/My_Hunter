/*
** EPITECH PROJECT, 2022
** day13
** File description:
** day13
*/

#include "include/my.h"

sfRenderWindow *create_window(unsigned int width,unsigned int height,int bits)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bits;
    window = sfRenderWindow_create(video_mode,"Pastis Hunt",sfResize |
    sfClose,NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void start_game(MAIN_T *GLOB)
{
    MOUSE = sfMouse_getPosition(WINDOW);
    if (MOUSE.x >= 788 && MOUSE.x <= 980 && MOUSE.y >= 251 && MOUSE.y <= 788) {
        if (EVENT.type == sfEvtMouseButtonPressed)
            game_loop(GLOB);
    }
}

int title_screen_loop(MAIN_T *GLOB)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
            sfRenderWindow_clear(WINDOW, sfWhite);
            sfRenderWindow_drawSprite(WINDOW, PICS[0].sprite, NULL);
            sfRenderWindow_display(WINDOW);
            start_game(GLOB);
            close_window(GLOB);
    }
    sfRenderWindow_destroy(WINDOW);
    return 0;
}

int check_param(int argc, char **argv)
{
    int i = 1;
    int count = 0;
    while (i != argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'h')
            count++;
        i++;
    }
    if (count == 0 && argc > 1) {
        write(2, "Wrong arguments", 16);
    }
    if (count > 0) {
        my_putstr("My_hunter description :\n");
        my_putstr("Click on the bottle to increase your score.\n");
        my_putstr("If you miss the bottle 3 time, it's game over.\n");
        my_putstr("Have fun!\n");
        return 1;
    }
    return 0;
}

int main (int argc, char **argv, char ** env)
{
    if (env[0] == NULL)
        return 84;
    if (check_param(argc, argv) == 0) {
    MAIN_T GLOB;
    GLOB.param.window = create_window(1920,1080,32);
    if (!GLOB.param.window)
        return 84;
    if (init_pictures(&GLOB) == 84)
        return 84;
    if (init_pictures2(&GLOB) == 84)
        return 84;
    if (init_text(&GLOB) == 84)
        return 84;
    if (init_game_over(&GLOB) == 84)
        return 84;
    if (init_heart(&GLOB) == 84)
        return 84;
    title_screen_loop(&GLOB);
    }
    return 0;
}
