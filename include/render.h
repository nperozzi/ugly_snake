#ifndef RENDER_H
#define RENDER_H

#include "snake.h"
#include "food.h"
#include "config.h"

void draw_field(char ch);
void draw_snake(char head_ch, char body_ch, snake_t *snake);
void draw_food(char ch, food_t *food);
void update_display(snake_t *snake, food_t *food);
void clear_screen(void);

#endif      //RENDER_H
