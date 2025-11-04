/*
EXERCISE: 
- make it 30*30
- make it so that you come out the other side when you go through the wall
- make it so that it leaves a trace (ETCH-A-SKETCH)
- place food. When the snake eats, POINTS - it grows
*/

#include <stdio.h>

#define SIZE_Y 20
#define SIZE_X 20

typedef struct
{
    int seg_x;
    int seg_y;
} snake_seg_t;

typedef struct
{
    snake_seg_t seg_array[900];
    int snake_size;
    int direction_y;        //-1 = left, 1 = right, 0 = no movement in that axis.
    int direction_x;        //-1 = up, 1 = down, 0 = no movement in that axis
} snake_t;


char display[SIZE_Y][SIZE_X];

void update_display(snake_t *snake, food_t *food);
void draw_field(char ch);
void draw_snake(char ch, snake_t *snake);

int main(void)
{
    snake_t snake;
        update_display(&snake, &food);
    return 0;
}

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

void draw_snake(char ch, snake_t *snake)
{
    for(int i = 0; i < snake->snake_size; i++)
    {
        display[snake->seg_array[i].seg_y][snake->seg_array[i].seg_x] = ch;
    }
}
void update_display(snake_t *snake, food_t *food)
{
    draw_field('#');
    draw_snake('@', snake);

    for(int y = 0; y < SIZE_Y; y++)
    {
        for(int x = 0; x < SIZE_X; x++)
        {
            printf("%c", display[y][x]);
        }
        printf("\n");
    }
}
