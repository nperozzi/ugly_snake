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


char display[SIZE_Y][SIZE_X];

void update_display(snake_t *snake, food_t *food);
void draw_field(char ch);

int main(void)
{
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
void update_display(snake_t *snake, food_t *food)
{
    draw_field('#');

    for(int y = 0; y < SIZE_Y; y++)
    {
        for(int x = 0; x < SIZE_X; x++)
        {
            printf("%c", display[y][x]);
        }
        printf("\n");
    }
}
