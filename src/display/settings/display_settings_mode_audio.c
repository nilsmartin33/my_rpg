/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_settings_mode_audio
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int display_settings_mode_audio(game_t *game,sfVector2i mouse)
{
    if (!game)
        return FAILURE;
    for (int index = 0; index < 8; ++index) {
        loop_button(mouse, game, game->settings_menu.audio.button1[index]->text,
        game->settings_menu.audio.button1[index]->pos_text);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->settings_menu.audio.button1[index]->rectangle, NULL);
        sfRenderWindow_drawText(game->window.window,
        game->settings_menu.audio.button1[index]->text, NULL);
    }
    return SUCCESS;
}
