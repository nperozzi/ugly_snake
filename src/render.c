#include "render.h"
#include "stdio.h"

char display[SIZE_Y][SIZE_X];

void draw_field(char ch)
{
    for (int y = 0; y < SIZE_Y; y++)
    {
        for (int x = 0; x < SIZE_X; x++)
        {
            if(y == 0 || y == (SIZE_Y - 1) || x == 0 || x == (SIZE_X -1))
            {
                display[y][x] = ch;
            }
            else
                display[y][x] = ' ';
        }
    }
}

void draw_snake(char head_ch, char body_ch, snake_t *snake)
{
    for(int i = 0; i < snake->snake_size; i++)
    {
        if(i == 0)
        {
            display[snake->seg_array[i].seg_y][snake->seg_array[i].seg_x] = head_ch;
        }
        else
        {
            display[snake->seg_array[i].seg_y][snake->seg_array[i].seg_x] = body_ch;
        }
    }
}

void draw_food(char ch, food_t *food)
{
    display[food->position_y][food->position_x] = ch;
}

void update_display(snake_t *snake, food_t *food)
{
    draw_field('#');
    draw_snake('O', 'o', snake);
    draw_food('*', food);

    for(int y = 0; y < SIZE_Y; y++)
    {
        for(int x = 0; x < SIZE_X; x++)
        {
            printf("%c", display[y][x]);
        }
        printf("\n");
    }
}

void clear_screen(void)
{
    printf("\033[H");
    printf("\e[1;1H\e[2J");
}
