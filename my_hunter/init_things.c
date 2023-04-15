/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** init things
*/
#include "include/my.h"

int init_pictures(MAIN_T *GLOB)
{
    PICS = malloc(sizeof(PIC_T) * 5);
    if (!(PICS[0].texture = sfTcf("assets/title_screen.png", NULL)))
        return 84;
    PICS[0].sprite = sfSprite_create();
    PICS[0].scale.x = 0.92;
    PICS[0].scale.y = 0.92;
    sfSprite_setTexture(PICS[0].sprite,PICS[0].texture,
                        sfTrue);
    sfSprite_setScale(PICS[0].sprite, PICS[0].scale);
    if (!(PICS[1].texture = sfTcf("assets/bar.jpg", NULL)))
        return 84;
    PICS[1].sprite = sfSprite_create();
    PICS[1].scale.x = 1;
    PICS[1].scale.y = 1.12;
    sfSprite_setTexture(PICS[1].sprite, PICS[1].texture,
                        sfTrue);
    sfSprite_setScale(PICS[1].sprite, PICS[1].scale);
    return 0;
}

int init_pictures2(MAIN_T *GLOB)
{
    if (!(PICS[2].texture = sfTcf("assets/bottle_ricard.png",NULL)))
        return 84;
    PICS[2].sprite = sfSprite_create();
    PICS[2].scale.x = 0.3;
    PICS[2].scale.y = 0.3;
    PICS[2].position.x = 0;
    PICS[2].position.y = 600;
    PICS[2].origin.x = 133;
    PICS[2].origin.y = 264.5;
    sfSprite_setTexture(PICS[2].sprite, PICS[2].texture, sfTrue);
    sfSprite_setScale(PICS[2].sprite, PICS[2].scale);
    sfSprite_setPosition(PICS[2].sprite, PICS[2].position);
    sfSprite_setOrigin(PICS[2].sprite, PICS[2].origin);
    return 0;
}

int init_heart(MAIN_T *GLOB)
{
    if (!(PICS[3].texture = sfTcf("assets/heart.png",NULL)))
        return 84;
    PICS[3].rect_sprite.height = 50;
    PICS[3].rect_sprite.width = 43;
    PICS[3].rect_sprite.left = 39;
    PICS[3].rect_sprite.top = 120;
    PICS[3].sprite = sfSprite_create();
    PICS[3].position.x = 500;
    PICS[3].position.y = 100;
    sfSprite_setTexture(PICS[3].sprite, PICS[3].texture,
                        sfTrue);
    sfSprite_setTextureRect(PICS[3].sprite, PICS[3].rect_sprite);
    sfSprite_setPosition(PICS[3].sprite, PICS[3].position);
    return 0;
}

int init_text(MAIN_T *GLOB)
{
    TEXT = malloc(sizeof(TEXT_T) * 2);
    TEXT[0].text = sfText_create();
    if (!(TEXT[0].font = sfFont_createFromFile("assets/RockFont.ttf")))
        return 84;
    TEXT[0].pos.x = 100;
    TEXT[0].pos.y = 0;
    sfText_setFont(TEXT[0].text,TEXT[0].font);
    sfText_setString(TEXT[0].text, "Score : ");
    sfText_setPosition(TEXT[0].text, TEXT[0].pos);
    sfText_setColor(TEXT[0].text, sfBlack);

    TEXT[1].text = sfText_create();
    TEXT[1].pos.x = 275;
    TEXT[1].pos.y = 0;
    sfText_setFont(TEXT[1].text,TEXT[0].font);
    sfText_setPosition(TEXT[1].text, TEXT[1].pos);
    sfText_setColor(TEXT[1].text, sfBlack);
    return 0;
}

void init_game_param (MAIN_T *GLOB)
{
    GAME.rotate = 35;
    GAME.speed_x = 150;
    GAME.speed_y = 100;
    GAME.sens_bottle = 0;
    GAME.score_count = 0;
    GAME.life = 3;
}
