#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "render.h"

void init_game(snake_t *snake, food_t *food);
void delay_milliseconds(int ms_delay);

int main(void)
{
    snake_t snake;
    food_t food;
    init_game(&snake, &food);

    while(true)
    {
        get_user_input(&snake);
        move_snake(&snake);
        test_snake_colition(&snake);
        test_get_food(&food, &snake);
        update_display(&snake, &food);
        delay_milliseconds(500);
        clear_screen();
    }
    return 0;
}

void init_game(snake_t *snake, food_t *food)
{
    snake->seg_array[0].seg_x = 15;
    snake->seg_array[0].seg_y = 15;
    snake->snake_size = 1;
    snake->direction_x = 1;
    snake->direction_y = 0;

    srand(time(NULL));

    update_food(food, snake);
}



void delay_milliseconds(int ms_delay)
{
    clock_t start_time = clock();
    clock_t wait_ticks = (ms_delay * CLOCKS_PER_SEC) / 1000;

    while ((clock() - start_time) < wait_ticks)
    {
        //do nothing
    }
}
