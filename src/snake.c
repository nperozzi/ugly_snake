#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "config.h"


void move_snake(snake_t *snake, int offset_x, int offset_y)
{
    for (int seg_index = (snake->snake_size - 1); seg_index >= 0; seg_index--)
    {
        if (seg_index == 0)
        {
            snake->seg_array[seg_index].seg_x += snake->direction_x;
            snake->seg_array[seg_index].seg_y += snake->direction_y; 
        }
        else
        {
            snake->seg_array[seg_index].seg_x = snake->seg_array[seg_index - 1].seg_x;
            snake->seg_array[seg_index].seg_y = snake->seg_array[seg_index - 1].seg_y;
        }
    }

     const int playable_top_limit = offset_y + 1;
     const int playable_bottom_limit = SIZE_Y - 2;
     const int playable_left_limit = offset_x + 1;
     const int playable_right_limit = SIZE_X - 2;

    if (snake->seg_array[0].seg_x < playable_left_limit)
        snake->seg_array[0].seg_x = playable_right_limit;
    if (snake->seg_array[0].seg_x > playable_right_limit)
        snake->seg_array[0].seg_x = playable_left_limit;
    if (snake->seg_array[0].seg_y < playable_top_limit)
        snake->seg_array[0].seg_y = playable_bottom_limit;
    if (snake->seg_array[0].seg_y > playable_bottom_limit)
        snake->seg_array[0].seg_y = playable_top_limit;
}

void get_user_input(snake_t *snake)
{
    if(_kbhit())
    {
        char arrows_code = _getch();
        if(arrows_code == -32)      //-32 is the keyboard arrow identifier code in my computer.
        {
            char key = _getch();
            switch (key)
            {
                case 72:    //Arrow UP
                    if(snake->direction_y == 1 || snake->direction_y == -1)
                    {
                        break;
                    }    

                    snake->direction_x = 0;
                    snake->direction_y = -1;
                    break;
                case 80:    //Arrow DOWN
                    if(snake->direction_y == 1 || snake->direction_y == -1)
                    {
                        break;
                    }    

                    snake->direction_x = 0;
                    snake->direction_y = 1;
                    break;
                case 75:    //Arrow LEFT
                    if(snake->direction_x == 1 || snake->direction_x == -1)
                    {
                        break;
                    }    

                    snake->direction_x = -1;
                    snake->direction_y = 0;
                    break;
                case 77:    //Arrow RIGHT
                    if(snake->direction_x == 1 || snake->direction_x == -1)
                    {
                        break;
                    }    

                    snake->direction_x = 1;
                    snake->direction_y = 0;
                    break;       
            }
        }
    }
}

void test_snake_colition(snake_t *snake)
{
    for(int i = 1; i < snake->snake_size; i++)
    {
        if(snake->seg_array[0].seg_x == snake->seg_array[i].seg_x && snake->seg_array[0].seg_y == snake->seg_array[i].seg_y)
        {
            printf("Game Over\n");
            exit(1);
        }
    }
}
