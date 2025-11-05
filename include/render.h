#ifndef RENDER_H
#define RENDER_H

#include "snake.h"
#include "food.h"
#include "config.h"

void update_display(snake_t *snake, food_t *food, unsigned int *score);
void clear_screen(void);

#endif      //RENDER_H
