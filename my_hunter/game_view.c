/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** game_view my_hunter
*/

#include "include/my.h"

void display_things (MAIN_T *GLOB)
{
    sfRenderWindow_drawSprite(WINDOW, PICS[1].sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PICS[2].sprite, NULL);
    if (GAME.life > 0) {
        PICS[3].position.x = 845;
        PICS[3].position.y = 0;
        sfSprite_setPosition(PICS[3].sprite, PICS[3].position);
        sfRenderWindow_drawSprite(WINDOW, PICS[3].sprite, NULL);
    } if (GAME.life >= 2) {
        PICS[3].position.x = 895;
        PICS[3].position.y = 0;
        sfSprite_setPosition(PICS[3].sprite, PICS[3].position);
        sfRenderWindow_drawSprite(WINDOW, PICS[3].sprite, NULL);
    } if (GAME.life >= 3) {
        PICS[3].position.x = 945;
        PICS[3].position.y = 0;
        sfSprite_setPosition(PICS[3].sprite, PICS[3].position);
        sfRenderWindow_drawSprite(WINDOW, PICS[3].sprite, NULL);
    }
    sfRenderWindow_drawText(WINDOW, TEXT[0].text, NULL);
    sfRenderWindow_drawText(WINDOW, TEXT[1].text, NULL);
}

void condition_game (MAIN_T *GLOB)
{
    if (PICS[2].position.y < 1)
        GAME.sens_bottle = 1;
    if (PICS[2].position.y > 990)
        GAME.sens_bottle = 0;
    int n = rand() % 1000 + 1;
    if (PICS[2].position.x > 1980.0) {
        PICS[2].position.x = 0;
        PICS[2].position.y = n;
        GAME.life -= 1;
    } if (GAME.sens_bottle == 0)
        PICS[2].position.y -= GAME.speed_y * GAME.delta;
    if (GAME.sens_bottle == 1)
        PICS[2].position.y += GAME.speed_y * GAME.delta;
    sfSprite_setPosition(PICS[2].sprite, PICS[2].position);
    PICS[2].rect = sfSprite_getGlobalBounds(PICS[2].sprite);
    if (click_bottle(GLOB) == 1) {
        GAME.score_count += 1;
        GAME.speed_x += 50;
        GAME.speed_y += 26;
    }
}

void close_window(MAIN_T *GLOB)
{
    while (sfRenderWindow_pollEvent(WINDOW, &EVENT)) {
        if (GLOB->param.event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
    }
}

int game_loop(MAIN_T *GLOB)
{
    float timer;
    init_game_param(GLOB);
    GAME.clock = sfClock_create();
    GAME.clock2 = sfClock_create();
    while (sfRenderWindow_isOpen(WINDOW)) {
        GAME.delta = sfTime_asSeconds(sfClock_restart(GAME.clock));
        timer = sfTime_asSeconds(sfClock_getElapsedTime(GAME.clock2));
        sfRenderWindow_clear(WINDOW, sfWhite);
        GAME.rotate += GAME.speed_x * GAME.delta;
        GAME.str_score = my_int_to_str(GAME.score_count);
        display_things(GLOB);
        sfRenderWindow_display(WINDOW);
        sfSprite_setRotation(PICS[2].sprite, GAME.rotate);
        condition_game(GLOB);
        if (timer > 0.09) {
            PICS[3].rect_sprite.left += 45;
            sfClock_restart(GAME.clock2);
        }
        game_loop2(GLOB);
    } return 0;
}

int click_bottle(MAIN_T *GLOB)
{
    int score = 0;
    char * str;
    float n = rand() % 1000 + 1;
    MOUSE = sfMouse_getPosition(WINDOW);
    if (sfFloatRect_contains(&PICS[2].rect, MOUSE.x, MOUSE.y) == sfTrue) {
        if (EVENT.type == sfEvtMouseButtonPressed) {
            PICS[2].position.x = 0;
            PICS[2].position.y = n;
            return 1;
        }
    }
    return 0;
}
