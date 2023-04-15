/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** struct my_hunter
*/

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H
typedef struct PICTURES {
    sfTexture *texture;
    sfSprite  *sprite;
    sfVector2f scale;
    sfVector2f origin;
    sfVector2f position;
    sfFloatRect rect;
    sfIntRect rect_sprite;
} PIC_T;

typedef struct GAME_PARAM {
    int score_count;
    char *str_score;
    float rotate;
    float speed_x;
    float speed_y;
    int sens_bottle;
    sfClock *clock;
    sfClock *clock2;
    float delta;
    int life;
} GAME_T;

typedef struct WINDOW {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mouse_pos;
} WIN_T;

typedef struct STR {
    sfText *text;
    sfVector2f pos;
    sfFont *font;
} TEXT_T;

typedef struct MAIN_STRUCT {
    PIC_T *pictures;
    WIN_T param;
    TEXT_T *text;
    GAME_T game;
} MAIN_T;
#endif
