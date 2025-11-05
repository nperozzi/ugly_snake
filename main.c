/*
EXERCISE: 
- make it 30*30
- make it so that you come out the other side when you go through the wall
- make it so that it leaves a trace (ETCH-A-SKETCH)
- place food. When the snake eats, POINTS - it grows
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

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

typedef struct
{
    int position_x;
    int position_y;
} food_t;

char display[SIZE_Y][SIZE_X];

void update_display(snake_t *snake, food_t *food);
void draw_field(char ch);
void draw_snake(char ch, snake_t *snake);
void init_game(snake_t *snake, food_t *food);
void get_user_input(snake_t *snake);
void move_snake(snake_t *snake);
void clear_screen(void);
void delay_milliseconds(int ms_delay);
void update_food(food_t *food);

int main(void)
{
    snake_t snake;
    food_t food;
    init_game(&snake, &food);

    while(true)
    {
        get_user_input(&snake);
        move_snake(&snake);
        if(snake.seg_array[0].seg_x == food.position_x && snake.seg_array[0].seg_y == food.position_y)
        {
            update_food(&food);
            snake.snake_size++;
        }
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

    update_food(food);
}

void update_food(food_t *food)
{
    food->position_x = rand() % (SIZE_X-1) + 1;
    food->position_y = rand() % (SIZE_Y-1) + 1;
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

void draw_food(char ch, food_t *food)
{
    display[food->position_y][food->position_x] = ch;
}

void move_snake(snake_t *snake)
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

    if (snake->seg_array[0].seg_x <= 0)
        snake->seg_array[0].seg_x = SIZE_X - 2;
    if (snake->seg_array[0].seg_x >= SIZE_X - 1)
        snake->seg_array[0].seg_x = 0 + 1;
    if (snake->seg_array[0].seg_y <= 0)
        snake->seg_array[0].seg_y = SIZE_Y - 2;
    if (snake->seg_array[0].seg_y >= SIZE_Y - 1)
        snake->seg_array[0].seg_y = 0 + 1;
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

void update_display(snake_t *snake, food_t *food)
{
    draw_field('#');
    draw_snake('@', snake);
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
    printf("\e[1;1H\e[2J");
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
