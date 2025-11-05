#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

typedef struct
{
    int position_x;
    int position_y;
} food_t;

void update_food(food_t *food, snake_t *snake, int offset_x, int offset_y);
void test_get_food(food_t *food, snake_t *snake, unsigned int *score);

#endif      //FOOD_H
