/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** my_hunter game_loop
*/
#include "include/my.h"

void game_loop2(MAIN_T *GLOB)
{
    if (PICS[3].rect_sprite.left > 214) {
        PICS[3].rect_sprite.left = 39;
    }
    sfSprite_setTextureRect(PICS[3].sprite, PICS[3].rect_sprite);
    sfText_setString(TEXT[1].text, GAME.str_score);
    PICS[2].position.x += GAME.speed_x * GAME.delta;
    if (GAME.life <= 0)
        game_over_loop(GLOB);
    close_window(GLOB);
}
