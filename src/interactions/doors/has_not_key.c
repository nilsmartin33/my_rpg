/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** has_not_key
*/

#include "rpg.h"

#include "rpg.h"

static const char monologue[] = "Argh... It's locked";
static const char monologue2[] = "Maybe I can find the key here";

static void first_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, monologue);
    return;
}

static void second_dialogue(game_t *game)
{
    sfSprite_setTextureRect(game->dialogue.portrait,
                            (sfIntRect){1024 * 1, 1440 * 0, 1024, 1440});
    sfText_setString(game->dialogue.text, monologue2);
    return;
}

static void events(game_t *game, int *flag)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &evt))
        close_window(game, evt);
    if ((*flag) == 0)
        first_dialogue(game);
    if ((*flag) == 1) {
        first_dialogue(game);
        (*flag) += 1;
        return;
    }
    if ((*flag) == 2)
        second_dialogue(game);
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue)
        (*flag) += 1;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        (*flag) = 3;
    return;
}

void has_not_key_interaction(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfSprite_setTextureRect(game->dialogue.portrait,
                            (sfIntRect){1024 * 1, 1440 * 1, 1024, 1440});
    while (flag != 3 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    return;
}
