/*
** EPITECH PROJECT, 2022
** MY_HUNTER
** File description:
** includes for hunter
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include "my_struct.h"
    #include <unistd.h>

    #define sfTcf sfTexture_createFromFile
    #define WINDOW GLOB->param.window
    #define EVENT GLOB->param.event
    #define PICS GLOB->pictures
    #define MOUSE GLOB->param.mouse_pos
    #define TEXT GLOB->text
    #define GAME GLOB->game

    sfRenderWindow *create_window(unsigned int width,unsigned int height,
                                                                int bits);
    int game_loop(MAIN_T *GLOB);
    int click_bottle(MAIN_T *GLOB);
    char * my_int_to_str(int nb);
    int init_text(MAIN_T *GLOB);
    int title_screen_loop(MAIN_T *GLOB);
    void close_window(MAIN_T *GLOB);
    int init_pictures(MAIN_T *GLOB);
    int init_pictures2(MAIN_T *GLOB);
    void init_game_param (MAIN_T *GLOB);
    int init_game_over(MAIN_T *GLOB);
    int game_over_loop(MAIN_T *GLOB);
    void my_putstr(char const *str);
    void game_loop2(MAIN_T *GLOB);
    int init_heart(MAIN_T *GLOB);
#endif
