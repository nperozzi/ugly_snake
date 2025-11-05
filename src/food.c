#include "food.h"
#include <stdlib.h>
#include "stdbool.h"
#include "config.h"


void update_food(food_t *food, snake_t *snake)
{
    bool is_food_position_valid = false;
    while (!is_food_position_valid)
    {
        food->position_x = rand() % (SIZE_X - 2) + 1;
        food->position_y = rand() % (SIZE_Y - 2) + 1;
        is_food_position_valid = true;
    
        for (int i = 0; i < snake->snake_size; i++)
        {
            if(food->position_x == snake->seg_array[i].seg_x && food->position_y == snake->seg_array[i].seg_y)
            {
                is_food_position_valid = false;
                break;
            }
        }
    }
}


void test_get_food(food_t *food, snake_t *snake)
{
    if(snake->seg_array[0].seg_x == food->position_x && snake->seg_array[0].seg_y == food->position_y)
    {
        
        snake->snake_size++;
        snake->seg_array[snake->snake_size - 1] = snake->seg_array[snake->snake_size - 2];

        update_food(food, snake);
    }
}
