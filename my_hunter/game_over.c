/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** game_over_screen
*/
#include "include/my.h"

int init_game_over(MAIN_T *GLOB)
{
    if (!(PICS[4].texture = sfTcf("assets/game_over.jpg", NULL)))
        return 84;
    PICS[4].sprite = sfSprite_create();
    PICS[4].scale.x = 1;
    PICS[4].scale.y = 1;
    sfSprite_setTexture(PICS[4].sprite,PICS[4].texture,
                        sfTrue);
    sfSprite_setScale(PICS[4].sprite, PICS[4].scale);
    return 0;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
}

void exit_or_retry_game(MAIN_T *GLOB)
{
    MOUSE = sfMouse_getPosition(WINDOW);
    if (MOUSE.x >= 663 && MOUSE.x <= 877 && MOUSE.y >= 640 && MOUSE.y <=
    705) {
        if (EVENT.type == sfEvtMouseButtonPressed) {
            TEXT[0].pos.x = 100;
            TEXT[0].pos.y = 0;
            TEXT[1].pos.x = 275;
            TEXT[1].pos.y = 0;
            sfText_setPosition(TEXT[0].text, TEXT[0].pos);
            sfText_setPosition(TEXT[1].text, TEXT[1].pos);
            game_loop(GLOB);
        }
    }

    if (MOUSE.x >= 993 && MOUSE.x <= 1216 && MOUSE.y >= 645 && MOUSE.y <=
    705) {
        if (EVENT.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(WINDOW);
        }
    }
}

int game_over_loop(MAIN_T *GLOB)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfWhite);
        sfRenderWindow_drawSprite(WINDOW, PICS[4].sprite, NULL);
        TEXT[0].pos.x = 825;
        TEXT[0].pos.y = 250;
        sfText_setPosition(TEXT[0].text, TEXT[0].pos);
        TEXT[1].pos.x = 1000;
        TEXT[1].pos.y = 250;
        sfText_setPosition(TEXT[1].text, TEXT[1].pos);
        sfRenderWindow_drawText(WINDOW, TEXT[0].text, NULL);
        sfRenderWindow_drawText(WINDOW, TEXT[1].text, NULL);
        sfRenderWindow_display(WINDOW);
        exit_or_retry_game(GLOB);
        close_window(GLOB);
    }
    return 0;
}
